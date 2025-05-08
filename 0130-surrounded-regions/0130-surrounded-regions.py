def isValid(board, m, n, r, c):
    if(r < 0 or r >= m):
        return False
    
    if(c < 0 or c >= n):
        return False

    if(board[r][c] == 'Y' or board[r][c] == 'X'):
        return False

    return True

def dfs(board, m, n, r, c, dirs):
    board[r][c] = 'Y'

    for d in dirs:
        newR = r + d[0]
        newC = c + d[1]

        if(isValid(board, m, n, newR, newC)):
            dfs(board, m, n, newR, newC, dirs)




class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        # Description is little bit difficult to understand.
        # See: https://www.youtube.com/watch?v=BtdgAys4yMk
        # to understand.

        # Crux is, start from boundary nodes if that's a 'O', and
        # cover as much as you can.

        m = len(board)
        n = len(board[0])

        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        # for i in range(m):
        #     if(not (i == 0 or i == m-1)):
        #         continue
        #     for j in range(n):
        #         # if(not (j == 0 or j == n-1)):
        #         #     continue

        #         # if(board[i][j] == 'X' or board[i][j] == 'Y'):
        #         #     continue

        #         # print(i, j, board[i][j])
        #         dfs(board, m, n, i, j, dirs)

        for j in range(n):
            if(board[0][j] == 'O'):
                dfs(board, m, n, 0, j, dirs)
            if(board[m-1][j] == 'O'):
                dfs(board, m, n, m-1, j, dirs)

        for i in range(m):
            if(board[i][0] == 'O'):
                dfs(board, m, n, i, 0, dirs)
            if(board[i][n-1] == 'O'):
                dfs(board, m, n, i, n-1, dirs)

        for i in range(m):
            for j in range(n):
                if(board[i][j] == 'O'):
                    board[i][j] = 'X'
                if(board[i][j] == 'Y'):
                    board[i][j] = 'O'


        