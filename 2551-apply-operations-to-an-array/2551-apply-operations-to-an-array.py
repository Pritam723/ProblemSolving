class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        firstZeroIdx = -1
        for i in range(n-1):
            if(firstZeroIdx == -1 and nums[i] == 0): firstZeroIdx = i
            if(nums[i] == nums[i+1]):
                nums[i] = nums[i] * 2
                nums[i+1] = 0

        # print(nums)
        # print(firstZeroIdx)
        if(firstZeroIdx == -1): return nums
        
        l = firstZeroIdx
        r = firstZeroIdx + 1
        
        while(r < n):
            if(nums[r] == 0):
                r = r + 1
            else:
                nums[l], nums[r] = nums[r], nums[l]
                l = l + 1
                r = r + 1


        return nums