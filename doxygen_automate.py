#!/usr/bin/env python3
"""
doxygen_automate.py

Walks a project directory, rewrites C/C++ files with proper Doxygen
headers and cleaned-up inline comments using the Claude API,
then commits each file individually via git.

Usage:
    python doxygen_automate.py --path /path/to/your/project

Requirements:
    pip install anthropic
    ANTHROPIC_API_KEY must be set as an environment variable.
"""

import os
import sys
import argparse
import subprocess
import anthropic

# File extensions to process
TARGET_EXTENSIONS = {".c", ".cpp", ".h", ".hpp"}

SYSTEM_PROMPT = """You are a senior embedded systems engineer. Your job is to rewrite C/C++ source files to use professional Doxygen-style comments.

Rules:
1. Add a @file Doxygen block at the very top (before includes) with @file, @brief, @author (use "Author"), @date (use today's date), @version (use 1.0.0)
2. Add Doxygen /** */ blocks above every function, struct, enum, and typedef with @brief, @param[in/out], @return, @note or @warning where appropriate
3. Use inline /**< */ comments for struct/enum members
4. Remove redundant comments that just restate what the code obviously does (e.g., // increment i, // return result)
5. Keep comments that explain WHY something is done, hardware quirks, non-obvious logic, or datasheet references
6. Do NOT change any actual code — only modify or add comments
7. Return ONLY the complete rewritten file contents with no explanation, no markdown fences, no preamble"""


def get_rewritten_file(client: anthropic.Anthropic, filename: str, content: str) -> str:
    """Send file content to Claude and get back the Doxygen-annotated version."""
    message = client.messages.create(
        model="claude-sonnet-4-20250514",
        max_tokens=8096,
        system=SYSTEM_PROMPT,
        messages=[
            {
                "role": "user",
                "content": f"Filename: {filename}\n\n{content}"
            }
        ]
    )
    return message.content[0].text


def git_commit(filepath: str, repo_root: str) -> None:
    """Stage and commit a single file."""
    rel_path = os.path.relpath(filepath, repo_root)
    subprocess.run(["git", "add", rel_path], cwd=repo_root, check=True)
    commit_msg = f"docs: add Doxygen comments to {rel_path}"
    subprocess.run(["git", "commit", "-m", commit_msg], cwd=repo_root, check=True)
    print(f"  Committed: {commit_msg}")


def find_git_root(path: str) -> str | None:
    """Walk up directories to find the git repo root."""
    current = os.path.abspath(path)
    while current != os.path.dirname(current):
        if os.path.isdir(os.path.join(current, ".git")):
            return current
        current = os.path.dirname(current)
    return None


def collect_files(project_path: str) -> list[str]:
    """Recursively collect all target source files."""
    files = []
    for root, dirs, filenames in os.walk(project_path):
        # Skip hidden dirs and common non-source dirs
        dirs[:] = [d for d in dirs if not d.startswith(".") and d not in {"build", "cmake-build-debug", "cmake-build-release", "__pycache__", "node_modules"}]
        for fname in filenames:
            if os.path.splitext(fname)[1] in TARGET_EXTENSIONS:
                files.append(os.path.join(root, fname))
    return sorted(files)


def main():
    parser = argparse.ArgumentParser(description="Auto-add Doxygen comments and commit each file.")
    parser.add_argument("--path", required=True, help="Path to your project directory")
    parser.add_argument("--dry-run", action="store_true", help="Preview files without writing or committing")
    args = parser.parse_args()

    project_path = os.path.abspath(args.path)
    if not os.path.isdir(project_path):
        print(f"Error: '{project_path}' is not a valid directory.")
        sys.exit(1)

    api_key = os.environ.get("ANTHROPIC_API_KEY")
    if not api_key:
        print("Error: ANTHROPIC_API_KEY environment variable is not set.")
        sys.exit(1)

    repo_root = find_git_root(project_path)
    if not repo_root and not args.dry_run:
        print("Error: No git repository found. Initialize one with 'git init' first.")
        sys.exit(1)

    client = anthropic.Anthropic(api_key=api_key)
    files = collect_files(project_path)

    if not files:
        print("No C/C++ source files found.")
        sys.exit(0)

    print(f"Found {len(files)} file(s) to process.\n")

    for i, filepath in enumerate(files, 1):
        rel = os.path.relpath(filepath, project_path)
        print(f"[{i}/{len(files)}] Processing: {rel}")

        with open(filepath, "r", encoding="utf-8", errors="replace") as f:
            original = f.read()

        if args.dry_run:
            print("  [dry-run] Skipping write and commit.\n")
            continue

        try:
            rewritten = get_rewritten_file(client, os.path.basename(filepath), original)
        except Exception as e:
            print(f"  Claude API error: {e} — skipping file.\n")
            continue

        with open(filepath, "w", encoding="utf-8") as f:
            f.write(rewritten)
        print(f"  Rewritten.")

        try:
            git_commit(filepath, repo_root)
        except subprocess.CalledProcessError as e:
            print(f"  Git error: {e} — file was rewritten but not committed.\n")
            continue

        print()

    print("Done.")


if __name__ == "__main__":
    main()