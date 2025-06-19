class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        L = len(nums)
        ans = 0
        i = 0
        while(i < L):
            s = i
            e = s+1

            while(e != L and (nums[e] - nums[s] <= k)):
                e = e + 1
            
            ans = ans + 1
            
            i = e
        
        return ans