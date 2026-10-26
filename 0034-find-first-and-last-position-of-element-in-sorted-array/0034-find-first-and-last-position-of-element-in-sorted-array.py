class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        # find existence:
        e = len(nums) - 1
        s = 0

        exists = False
        while(s <= e):
            m = s + (e-s)//2
            key = nums[m]
            if(target == key):
                exists = True
                break
            elif(target > key):
                s = m + 1
            else:
                e = m - 1
        if(exists is False): return [-1,-1]


        ans_l = -1
        ans_r = -1

        # Search left most occ
        e = len(nums) - 1
        s = 0
        
        while(s <= e):
            m = s + (e-s)//2
            key = nums[m]

            if(target == key):
                ans_l = m # potential ans, but we can find better at left right?
                e = m - 1
            elif(target > key):
                s = m + 1
            else:
                e = m - 1
        
        # Search right most occ
        e = len(nums) - 1
        s = 0
        
        while(s <= e):
            m = s + (e-s)//2
            key = nums[m]

            if(target == key):
                ans_r = m
                s = m + 1
            elif(target > key):
                s = m + 1
            else:
                e = m - 1

        
        return [ans_l, ans_r]