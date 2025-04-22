class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10**9 + 7

        #k means k numbers have been picked, and treat as if strictly increasing
        #to reduce number of states. Then can calculate combinations of where each
        #number first occurs in the array (where there are duplicates in between)
        #1....2....4 -> 2 then 4 can start anywhere after 1, and would fill in with 1's
        #after the 1, 2's after the 2, and 4's after the 4

        @cache
        def rec(k, val):
            if k == n:
                return comb(n-1, k-1) #how many ways to place all but first value
            
            #add count if not placing anymore
            count = comb(n-1, k-1)
            
            #factor to reach next value
            for i in range(2, maxValue//val + 1):
                count = (count + rec(k+1, val*i)) % MOD
            return count
        
        total = 0
        for i in range(1, maxValue+1):
            total = (total + rec(1, i)) % MOD
        return total