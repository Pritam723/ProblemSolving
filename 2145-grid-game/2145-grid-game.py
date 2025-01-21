class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        # Maximizing path for robot 1 doesn't ensure the solution.
        # Great Explanation: https://www.youtube.com/watch?v=B90kG-ZlptE
        # See the examples. After R1 takes a path, R2 can only take either
        # upper part or lower part. Not both. So, just minimize the value
        # over max(upper, lower) for each i. Where i is the place where
        # R1 is taking "down" movement/turn.

        m = 2
        n = len(grid[0])

        ps1 = grid[0][0]
        ps2 = grid[1][0]

        for i in range(1,n):
            grid[0][i] = grid[0][i] + grid[0][i-1]
            grid[1][i] = grid[1][i] + grid[1][i-1]

        # print(grid)

        # Now decide for the break.

        minCost = 10**12

        for i in range(n):
            # So, we are breaking at index i.
            upperVal = grid[0][n-1] - grid[0][i] 
            lowerVal = 0 # In case i = 0
            if(i > 0): lowerVal = grid[1][i-1]

            cost = max(upperVal, lowerVal)

            minCost = min(cost, minCost)

        return minCost
