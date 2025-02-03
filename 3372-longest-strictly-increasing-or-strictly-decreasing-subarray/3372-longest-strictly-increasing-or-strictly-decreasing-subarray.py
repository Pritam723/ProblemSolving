class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        if(n == 0): return 0
        ans = 1 # Can't be less than 0.

        currentLongest = 1
        for i in range(1, n):
            if(nums[i] > nums[i-1]):
                currentLongest = currentLongest + 1
            else:
                currentLongest = 1

            ans = max(ans, currentLongest)

        currentLongest = 1
        for i in range(1, n):
            if(nums[i] < nums[i-1]):
                currentLongest = currentLongest + 1
            else:
                currentLongest = 1

            ans = max(ans, currentLongest)

        return ans