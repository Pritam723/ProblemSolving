class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)

        prefixSumm = 0

        for i in range(n):
            prefixSumm = prefixSumm + nums[i]
            nums[i] = prefixSumm
        
        print(nums)
        count = 0

        for i in range(n-1):
            if(2*nums[i] >= nums[n-1]):
                count += 1

        return count