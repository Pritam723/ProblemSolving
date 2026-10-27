class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        s = 0
        e = len(nums) - 1
        
        idx1 = e
        # 1,3,5,4,2
        # careful about: 1,2,3,4,5 and 5,4,3,2,1
        while(idx1 >= 1):
            if(nums[idx1] <= nums[idx1 - 1]):
                idx1 = idx1 - 1
            else:
                break
        # So either idx1 = 1 now, or it is at index 2 say. (1,3,5,4,2)
        idx1 = idx1 - 1
        print(idx1)
        if(idx1 == -1):
            print('Reversed thing')
            nums.reverse()
            return

        idx2 = e # starting from right, find idx2 in such a way that nums[idx2] > nums[idx1]
        while(idx2 > idx1):
            if(nums[idx2] > nums[idx1]):
                break
            idx2 = idx2 - 1

        nums[idx1], nums[idx2] = nums[idx2], nums[idx1]
        l = idx1 + 1

        while(l <= e):
            nums[l], nums[e] = nums[e], nums[l]

            l = l + 1
            e = e - 1

        return