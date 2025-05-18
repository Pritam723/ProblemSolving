class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 10**9 + 7
        
        # Generate all possible valid rows of length m (no two adjacent cells same color)
        def generate_rows():
            rows = []
            def backtrack(path):
                if len(path) == m:
                    rows.append(tuple(path))
                    return
                for color in [0, 1, 2]:
                    if not path or path[-1] != color:
                        backtrack(path + [color])
            backtrack([])
            return rows
        
        valid_rows = generate_rows()
        if not valid_rows:
            return 0
        
        # Precompute a transition map: from row1 to row2, if row2 can follow row1 (no same colors in same column)
        transition = {}
        for row1 in valid_rows:
            transition[row1] = []
            for row2 in valid_rows:
                valid = True
                for a, b in zip(row1, row2):
                    if a == b:
                        valid = False
                        break
                if valid:
                    transition[row1].append(row2)
        
        # Use dp with memoization: dp[i][row] = number of ways to color first i rows with i-th row being 'row'
        # Initialize for the first row
        dp = {}
        for row in valid_rows:
            dp[row] = 1
        
        for _ in range(1, n):
            new_dp = {}
            for row in valid_rows:
                total = 0
                for prev_row in transition.keys():
                    if row in transition[prev_row]:
                        total += dp[prev_row]
                        total %= MOD
                new_dp[row] = total
            dp = new_dp
        
        return sum(dp.values()) % MOD 