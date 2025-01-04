class Solution:
    def countUniquesInBetween(self, s, start, end):
        if(start > end):
            return 0
        if(start == end or start == end + 1):
            return 0
        
        charMap = [0]*26
        unique = 0
        i = start + 1
        while(i < end):
            chIdx = ord(s[i]) - ord('a')
            if(charMap[chIdx] == 1):
                pass
            else:
                charMap[chIdx] = charMap[chIdx] + 1
                unique += 1
            i += 1

        print(unique)
        return unique

    def countPalindromicSubsequence(self, s: str) -> int:
        # print(ord('a'))
        n = len(s)

        startIdx = [n]*26
        endIdx = [-1]*26
        
        i = 0
        for ch in s:
            # print(ch)
            chIdx = ord(ch) - ord('a')
            startIdx[chIdx] = min(startIdx[chIdx], i)
            endIdx[chIdx] = max(endIdx[chIdx], i)
            i = i + 1

        print(startIdx)
        print(endIdx)

        count = 0

        for i in range(26):
            count = count + self.countUniquesInBetween(s, startIdx[i], endIdx[i])

        return count