class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[nums[x]] for x in range(len(nums))]
           
            
        