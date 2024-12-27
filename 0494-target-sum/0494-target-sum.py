class Solution:

    def sol(self, nums, n, i, target, offset, dp):
        if(i == n and target == 0):
            return 1
        if(i == n): # So target != 0
            return -1

        # print(i, target)

        if(dp[i][target + offset] != -9999): return dp[i][target + offset]
        
        val = nums[i]

        # Say target = 10 now and val = 4. Including it wil make target = 6.
        # Including -ve of it will make target = 14.

        # Including +ve:
        op1 = self.sol(nums, n, i+1, target-val, offset, dp)
        op2 = self.sol(nums, n, i+1, target+val, offset, dp)

        if(op1 == -1): dp[i][target + offset] = op2
        elif(op2 == -1): dp[i][target + offset] = op1
        else: dp[i][target + offset] = op1 + op2

        return dp[i][target + offset]

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        i = 0
        summ = sum(nums)
        print(summ)
        
        # Problem of DP here is that target at worst case may go till target-summ. So use scale of +summ.
        # So, if summ = 10. And target = 3, We need range 3-10 to 3+10. Rather we will use 0 to 20 (Instead of -7 to +13)
        # So, always offset by target-summ

        offset = abs(target-summ)

        dp = []
        
        for index in range(n+1):
            dp.append([])
            for t in range(target+summ + offset + 1):
                dp[index].append(-9999)

        # print(dp)

        ans = self.sol(nums, n, i, target, offset, dp)
        if(ans == -1): return 0
        return ans
        