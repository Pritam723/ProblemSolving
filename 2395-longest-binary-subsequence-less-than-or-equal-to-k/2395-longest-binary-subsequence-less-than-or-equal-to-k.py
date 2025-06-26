class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        
        ans = 0
        n = len(s)
        
        if k > int(s, 2):
            return n
        
        for i in range(n):
            if int(s[n - 1 - i:], 2) > k:
                curr = i
                break
                
        if i == n - 1:
            return n

        ans = i + s[:n - i].count("0")
        
        return ans