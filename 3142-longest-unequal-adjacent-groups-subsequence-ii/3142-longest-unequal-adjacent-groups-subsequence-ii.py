class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        def hamming(w1, w2):
            return sum(a != b for a, b in zip(w1, w2)) == 1
        
        dp = [1] * n
        prev = [-1] * n

        for i in range(n):
            for j in range(i):
                if groups[i] != groups[j] and len(words[i]) == len(words[j]) and hamming(words[i], words[j]) :
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        prev[i] = j

        max_len = max(dp)
        max_idx = dp.index(max_len)

        res = []
        cur = max_idx

        while cur != -1:
            res.append(words[cur])
            cur = prev[cur]
        return res[::-1]
