/**
 * @file strCopy.c
 * @brief Implements a simple string copy function for null-terminated strings.
 *
 * Demonstrates how to copy a C string from source to destination using pointer arithmetic.
 */

/**
 * @brief Copies a null-terminated string from source to destination.
 *
 * @param s Pointer to the source string (null-terminated).
 * @param d Pointer to the destination buffer (must be large enough).
 */

#include <stdio.h>

void str_copy(char *s, char *d) {
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

int main(void) {
    char s[8] = "ABCDEFG";
    char d[8]; // destination buffer must be at least as large as source + null terminator
    str_copy(s, d);
    printf("%s\n", d);
    return 0;
}