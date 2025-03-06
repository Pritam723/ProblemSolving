class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        ans = [0,0]

        n = len(grid)

        for i in range(n):
            for j in range(n):
                valAtIdx = abs(grid[i][j])

                rowIdx = (valAtIdx - 1)//n
                colIdx = (valAtIdx - 1)%n

                if(grid[rowIdx][colIdx] < 0):
                    ans[0] = abs(valAtIdx)
                else:
                    grid[rowIdx][colIdx] = -grid[rowIdx][colIdx]
        print(grid)
        for i in range(n):
            for j in range(n):
                if(grid[i][j] > 0):
                    ans[1] = (i)*n + (j) + 1
                    return ans
        return ans              
                

