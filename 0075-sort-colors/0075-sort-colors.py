class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        low, mid = 0,0
        high = n-1

        while(mid <= high):
            if(nums[mid] == 2):
                nums[mid], nums[high] = nums[high], nums[mid]
                high = high - 1
            elif(nums[mid] == 1):
                mid = mid + 1
            else:
                nums[mid], nums[low] = nums[low], nums[mid]
                low = low + 1
                mid = mid + 1


            
        