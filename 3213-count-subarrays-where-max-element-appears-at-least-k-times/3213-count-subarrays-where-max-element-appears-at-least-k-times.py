class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_e=max(nums)
    
        if nums.count(max_e)<k:return 0

        res=0
        l=0
        N=len(nums)
        cur_cnt=0
        for r in range(N):
            cur_cnt+=nums[r]==max_e
            while cur_cnt>=k and l<=r:
                res+=(1+(N-r-1))
                cur_cnt-=nums[l]==max_e
                l+=1
        return res