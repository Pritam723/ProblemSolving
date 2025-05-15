class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        # Longest SS will start either with 0, or with 1.
        # So, just check which one is longer.
        # But if we think about it, it will always start from
        # index 0 only. Because it is subsequence. Even if
        # the case is: 1,1,1,1,1,0,1,1,1,1. And if we think 01
        # is max length, but still 101 gives longer sequence.
        n = len(groups)
        indices = [0]

        nextToFind = 1 - groups[0]

        for i in range(1, n):
            if(groups[i] == nextToFind):
                indices.append(i)
                nextToFind = 1 - groups[i]

        ans = []
        for idx in indices:
            ans.append(words[idx])

        return ans

