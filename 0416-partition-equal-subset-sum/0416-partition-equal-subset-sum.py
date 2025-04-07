import numpy as np

def sol(nums, i, n, target, dp):
    
    if(target < 0):
        return 0

    if(target == 0):
        return 1

    if(i == n):
        return 0

    if(dp[i][target] != -1):
        return dp[i][target]

    val = nums[i]
    # Either include val or exclude it.
    op1 = sol(nums, i+1, n, target - val, dp)

    op2 = sol(nums, i+1, n, target, dp)

    flag = 0

    if(op1 or op2):
        flag = 1

    dp[i][target] = flag

    return dp[i][target]

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        i = 0
        summ = 0
        for item in nums:
            summ += item

        if(summ % 2 == 1): return False

        target = summ//2

        # dp = np.zeros((n+1) * (target+1), dtype = int)

        # dp = dp.reshape(n+1, target+1)
        
        dp = np.full((n+1, target+1), -1)
        # print(dp)

        flag = sol(nums, i, n, target, dp)

        if(flag == 1):
            return True
        
        return False