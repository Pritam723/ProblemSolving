from collections import deque
import heapq

class Tuple:
    def __init__(self, val, idx):
        self.val = val
        self.idx = idx
    
    def __lt__(self, elem):
        if(self.val < elem.val): return True
        elif(self.val == elem.val): return self.idx < elem.idx
        else: return False

class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        elems = []

        for idx, val in enumerate(nums):
            elems.append(Tuple(val, idx))

        heapq.heapify(elems)
        ans = 0
        while len(elems) > 0:
            elem = heapq.heappop(elems)
            print(f"{elem.val} and {elem.idx}")
            idx = elem.idx
            val = nums[idx]

            if(val == 0): continue

            ans = ans + val

            leftIdx = idx - 1
            rightIdx = idx + 1

            if(leftIdx >= 0): nums[leftIdx] = 0
            if(rightIdx < n): nums[rightIdx] = 0

        return ans