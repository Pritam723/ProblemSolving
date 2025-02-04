class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)
        maxSumm = nums[0]

        currentSumm = nums[0]

        for i in range(1, n):
            if(nums[i] > nums[i-1]):
                currentSumm = currentSumm + nums[i]
            else:
                currentSumm = nums[i]
            maxSumm = max(maxSumm, currentSumm)

        return maxSumm