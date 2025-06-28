class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        # Min Heap
        subsequence = []
        min_heap = []

        for i, num in enumerate(nums): 
            heapq.heappush(min_heap, (num, i))
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        min_heap.sort(key=lambda x: x[1])
        
        for num, _ in min_heap:
            subsequence.append(num)

        return subsequence

        # O(n log k) time.
        # O(k) space.