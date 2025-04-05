from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = []
        dq = deque([]) # Will only store indices.
        
        i = 0
        while(i < k):
            val = nums[i]
            while(len(dq) > 0 and nums[dq[-1]] <= val):
                dq.pop()
            dq.append(i)
            i = i + 1
        # print(dq)

        # So, my first window is ready. Now, start from i = k and process
        # one by one.
        ans.append(nums[dq[0]])

        i = k
        while(i < n):
            val = nums[i]
            
            # Before pushing it, we need to remove indices which are outdated.
            # Like for i = k, i = 0 is outdated.
            while(len(dq) > 0 and dq[0] <= i-k):
                dq.popleft()
            
            while(len(dq) > 0 and nums[dq[-1]] <= val):
                dq.pop()
            dq.append(i)

            ans.append(nums[dq[0]])

            i = i + 1

        return ans    