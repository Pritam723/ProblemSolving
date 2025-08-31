class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row_set = [set() for i in range(9)]
        col_set = [set() for i in range(9)]
        box_set = [[set() for i in range(3)] for j in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    row_set[i].add(board[i][j])
                    col_set[j].add(board[i][j])
                    box_set[i//3][j//3].add(board[i][j])
        def start_filling(i, j):
            if i == 8 and j == 9:
                return True
            if j == 9:
                return start_filling(i+1, 0)
            if board[i][j] != ".":
                return start_filling(i, j+1)
            for n in range(1, 9+1):
                if str(n) not in row_set[i] and str(n) not in col_set[j] and str(n) not in box_set[i//3][j//3]:
                    board[i][j] = str(n)
                    row_set[i].add(str(n))
                    col_set[j].add(str(n))
                    box_set[i//3][j//3].add(str(n))
                    if start_filling(i, j+1):
                        return True
                    row_set[i].remove(str(n))
                    col_set[j].remove(str(n))
                    box_set[i//3][j//3].remove(str(n))
                    board[i][j] = "."
            return False
        
        start_filling(0, 0)