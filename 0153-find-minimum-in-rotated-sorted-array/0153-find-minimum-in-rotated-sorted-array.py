class Solution:
    def findMin(self, nums: list[int]) -> int:
        s = 0
        e = len(nums) - 1
        ans = nums[0]
        # min number is the only position for which nums[i] < nums[i-1]
        # but careful if i = 0.
        if(nums[s] < nums[e]): return nums[s]

        # Now if u see, the 2 Lines are actually / and / and arr[0] is always > any
        # elem of L2. Also we are sure that ans is first element of L2.
        base = nums[0]
        while(s <= e):
            m = s + (e-s)//2
            print(f'mid is {m}')
            
            if(nums[m] >= base):
                # We are at line1. So try looking right. Its fine if you
                # go right in L2.
                s = m + 1
            elif(nums[m] < base):
                # we are at L2 and its a potential ans
                ans = min(ans, nums[m])
                # and we should still look at left.
                e = m - 1

        return ans
