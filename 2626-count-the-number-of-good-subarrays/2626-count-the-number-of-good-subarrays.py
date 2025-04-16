class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        pairs = 0
        ans = 0
        counter = defaultdict(int)
        l = 0

        for r in range(len(nums)):
            counter[nums[r]] += 1
            if counter[nums[r]] >= 2:
                pairs += counter[nums[r]] * (counter[nums[r]] - 1) // 2 # Add curr pairs
                pairs -= (counter[nums[r]] - 1) * (counter[nums[r]] - 2) // 2 # Sub prev pairs
            while pairs >= k:
                ans += len(nums) - r # Add curr + right subarrs
                counter[nums[l]] -= 1
                if counter[nums[l]] >= 1:
                    pairs -= (counter[nums[l]] + 1) * (counter[nums[l]]) // 2 # Sub prev pairs
                    pairs += (counter[nums[l]]) * (counter[nums[l]] - 1) // 2 # Add curr pairs
                l += 1

        return ans