class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        N = len(nums)
        chunks = []
        for g, t in groupby(nums, key = lambda x: minK <= x <= maxK):
            if g:
                chunks.append(list(t))
            
        if minK == maxK:
            def solve_same(chunk):
                prev = 0
                total = 0
                for x in chunk:
                    prev += 1
                    total += prev
                return total
            total = 0
            for chunk in chunks:
                total += solve_same(chunk)
            return total
        
        def solve_diff(chunk):
            last_min_seen = None
            last_max_seen = None
            total = 0

            for index, x in enumerate(chunk):
                if x == minK:
                    last_min_seen = index
                if x == maxK:
                    last_max_seen = index
                
                if last_min_seen is not None and last_max_seen is not None:
                    total += min(last_min_seen, last_max_seen) + 1
            return total
        
        total = 0
        for chunk in chunks:
            total += solve_diff(chunk)
        return total