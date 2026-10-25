class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 0 to low-1 -> 0
        # low to mid-1 -> 1
        # high+1 to n-1 -> 2

        n = len(nums)

        low = mid = 0
        high = n-1

        # [0,0,1,1,2,2] -> high = 1

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

            print(nums)

