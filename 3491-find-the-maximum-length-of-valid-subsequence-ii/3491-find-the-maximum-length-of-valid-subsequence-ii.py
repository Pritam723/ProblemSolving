class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        def fn(r, k):
            dp = [0] * k
            for x in nums:
                rx = x % k
                dp[rx] = max(dp[rx], dp[(r - rx) % k] + 1)
            res = max(dp)
            return res

        ans = max(fn(r, k) for r in range(k))
        print(ans)
        return ans

        