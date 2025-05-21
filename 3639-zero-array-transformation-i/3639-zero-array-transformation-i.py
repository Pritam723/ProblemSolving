class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        pref = [0]*(len(nums)+1)
        for l, r in queries:
            pref[l] += 1
            pref[r+1] -= 1
        s = 0
        for d, num in zip(pref, nums):
            s += d
            if s < num:
                return False
        return True 