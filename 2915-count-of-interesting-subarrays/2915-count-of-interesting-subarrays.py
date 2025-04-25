class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        prefix_count = defaultdict(int)
        prefix_count[0] = 1
        cnt_mod = 0 
        interesting_count = 0
        for num in nums:
            if num % modulo == k:
                cnt_mod += 1
            remainder = cnt_mod % modulo
            target = (remainder - k) % modulo
            interesting_count += prefix_count[target]
            prefix_count[remainder] += 1
        return interesting_count