class Solution:
    def dfs(self, grid, r, c, m, n, totalFish, dirs):
        totalFish[0] = totalFish[0] + grid[r][c]

        grid[r][c] = 0 # Marking Visited with 0.

        for direction in dirs:
            newR = r + direction[0]
            newC = c + direction[1]

            if(newR >= 0 and newR < m and newC >= 0 and newC < n and grid[newR][newC] != 0):
                self.dfs(grid, newR, newC, m, n, totalFish, dirs)


    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        maxFish = 0
        dirs = [[0,1],[0,-1],[1,0],[-1,0]]

        for r in range(m):
            for c in range(n):
                if(grid[r][c] == 0): continue
                totalFish = [0]
                self.dfs(grid, r, c, m, n, totalFish, dirs)

                maxFish = max(totalFish[0], maxFish)

        return maxFish