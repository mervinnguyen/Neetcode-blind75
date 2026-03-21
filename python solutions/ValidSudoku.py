#You are given a 9 x 9 sudoku board. A sudoku board is valid if the following rules are followed.
#1. Each row ust contain the digits 1-9 without duplicates
#2. Each column must contain the digits 1-9 without duplicates.
#3. Each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9 without duplicates
#Return true if the sudoku board ius valid, otherwise return false. 

class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        #Check each row and make sure it contains 1-9 without duplicates
        for row in range(9):
            seen = set()
            for i in range(9):
                if board[row][i] == ".":
                    continue
                if board[row][i] in seen:
                    return False        # return false if there are duplicates from 1-9
                seen.add(board[row][i])
        
        #Check each column
        for column in range(9):
            seen = set()
            for i in range(9):
                if board[i][column] == ".":
                    continue
                if board[i][column] in seen:
                    return False
                seen.add(board[i][column])
        
        for square in range(9):
            seen = set()
            for i in range(3):
                for j in range(3):
                    row = (square // 3) * 3 + i
                    col = (square % 3) * 3 + j
                    if board[row][col] == ".":
                        continue
                    if board[row][col] in seen:
                        return False
                    seen.add(board[row][col])
        return True
    
    #Create test cases
board1 = [["5","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],    
            ["8",".",".",".","6",".",".",".","3"],
            ["4",".",".","8",".","3",".",".","1"],
            ["7",".",".",".","2",".",".",".","6"],
            [".","6",".",".",".",".","2","8","."],
            [".",".",".","4","1","9",".",".","5"],
            [".",".",".",".","8",".",".","7","9"]]

board2 = [["8","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
            [".","9","8",".",".",".",".","6","."],    
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

solution = Solution()
print(solution.isValidSudoku(board1))  #Expected output: True
print(solution.isValidSudoku(board2))  #Expected output: False
        