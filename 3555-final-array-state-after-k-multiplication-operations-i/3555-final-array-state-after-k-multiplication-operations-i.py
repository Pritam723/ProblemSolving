import heapq
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        elems = []
        for index, item in enumerate(nums):
            elems.append([item, index])
        
        heapq.heapify(elems)
        # By default it is a min heap so no worry.
        i = 0
        while(i < k):
            elem = heapq.heappop(elems)
            newElem = [elem[0]*multiplier, elem[1]]
            heapq.heappush(elems, newElem)
            i = i + 1

        ans = [0]*len(nums)

        while(len(elems) > 0):
            elem = heapq.heappop(elems)
            index = elem[1]
            item = elem[0]
            # print(index)
            ans[index] = item

        return ans
