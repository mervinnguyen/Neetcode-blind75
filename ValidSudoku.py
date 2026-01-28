#You are given a 9 x 9 sudoku board. A sudoku board is valid if the following rules are followed.
#1. Each row ust contain the digits 1-9 without duplicates
#2. Each column must contain the digits 1-9 without duplicates.
#3. Each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9 without duplicates
#Return true if the sudoku board ius valid, otherwise return false. 

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
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

        