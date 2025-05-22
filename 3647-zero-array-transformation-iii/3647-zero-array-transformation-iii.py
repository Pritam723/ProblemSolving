class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:

        heap = []
        hs = defaultdict(list)

        for i, j in queries:
            hs[i].append(j)
        df = [0] * (len(nums) + 1)
        diff = 0
        for i in range(len(nums)):
            
            diff += df[i]

            for e in hs[i]:
                heapq.heappush(heap, -e)
            
            

            while heap and diff < nums[i]:
                minus = heapq.heappop(heap)
                if -minus < i: continue
                df[-minus + 1] -= 1
                diff += 1
                
            if not heap and diff < nums[i]: return -1
        
        return len(heap)



            
        