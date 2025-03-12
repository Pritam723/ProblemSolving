class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)

        # Can be solved using binary search.
        # Need to find first index having value > 0
        # And Last index having value < 0
        idx1, idx2 = n, -1


        s, e = 0, n-1
        
        while(s <= e):
            mid = s + (e-s)//2
            val = nums[mid]

            if(val > 0):
                # Potential Index
                idx1 = mid
                e = mid - 1
            else:
                # So, val is <= 0.
                # Surley not eligible.
                s = mid + 1

        # So, there are n - idx1 no. of positives.


        s, e = 0, n-1
        
        while(s <= e):
            mid = s + (e-s)//2
            val = nums[mid]

            if(val < 0):
                # Potential Index
                idx2 = mid
                s = mid + 1
            else:
                # So, val is >= 0.
                # Surley not eligible.
                e = mid - 1

        # So, there are idx2 + 1 no. of positives.

        return max(n-idx1, idx2+1)