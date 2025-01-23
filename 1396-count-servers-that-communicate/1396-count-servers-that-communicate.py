class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        rowMap = [0]*m
        colMap = [0]*n
        
        ans = 0
        
        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if(cell == 0): continue

                # Otherwise it is a server.
                rowMap[i] = rowMap[i] + 1
                colMap[j] = colMap[j] + 1

        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if(cell == 0): continue

                # Otherwise it is a server.
                if(rowMap[i] > 1 or colMap[j] > 1): ans = ans + 1
                

        return ans