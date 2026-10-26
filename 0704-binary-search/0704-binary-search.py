class Solution:
    def search(self, nums: list[int], target: int) -> int:
        # Binary search
        e = len(nums) - 1
        s = 0

        while(s <= e):
            mid = s+(e-s)//2
            if(target == nums[mid]):
                return mid
            elif(target > nums[mid]):
                s = mid + 1
            else:
                e = mid - 1

        return -1