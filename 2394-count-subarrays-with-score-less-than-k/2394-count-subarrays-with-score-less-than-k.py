class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        sarr = [nums[0]]

        for n in nums[1:]:
            sarr.append(n+sarr[-1])
        l = 0
        count = 0
        for r in range(len(nums)):
            # l=0
            curr_minus = l-1
            if curr_minus==-1:
                minus = 0
            else:
                minus = sarr[curr_minus]
            while l<r and ((r-l)+1)*(sarr[r]-minus)>=k:
                # print(((r-l)+1)*(sarr[r]-minus))
                l+=1
                curr_minus = l-1
                if curr_minus==-1:
                    minus = 0
                else:
                    minus = sarr[curr_minus]
            else:
                if l<=r and  ((r-l)+1)*(sarr[r]-minus)<k:
                    # print(l,r,)
                    count += (r-l+1)
        return count