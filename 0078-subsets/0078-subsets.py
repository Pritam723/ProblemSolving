# from collections import deque

def sol(nums, n, i, pa, ans):
    if(i == n):
        ans.append(pa.copy())
        return
    
    val = nums[i]

    # Include it.
    pa.append(val)
    sol(nums, n, i + 1, pa, ans)

    # Exclude it.
    pa.pop()
    sol(nums, n, i + 1, pa, ans)

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        i = 0
        ans = []
        pa = []

        sol(nums, n, i, pa, ans)

        return ans
