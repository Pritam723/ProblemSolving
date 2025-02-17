class Solution:
    def getFactorialValues(self, n):
        factorialValues = [1,1,2,6,24,120,720,5040] # Till 7 is fine.
        return factorialValues[n]

    def sol(self, charCount, ans, i, totalChars, denominator):
        # print(i)
        if(i == 26):
            ans[0] = ans[0] + int(self.getFactorialValues(totalChars)/denominator)
            return

        count = charCount[i]

        if(count == 0):
            self.sol(charCount, ans, i + 1, totalChars, denominator)
        else:
            for _take in range(count + 1): # If there are 3 'A's, I can choose 0,1,2 or 3
                totalChars = totalChars + _take
                denominator = denominator * self.getFactorialValues(_take)
                self.sol(charCount, ans, i + 1, totalChars, denominator)
                # now track back.
                totalChars = totalChars - _take
                denominator = int(denominator/self.getFactorialValues(_take))

        return

    def numTilePossibilities(self, tiles: str) -> int:
        charCount = [0]*26

        for ch in tiles:
            chIdx = ord(ch) - ord('A')
            charCount[chIdx] = charCount[chIdx] + 1

        ans = [0]
        i = 0

        totalChars = 0
        # numerator = 1
        denominator = 1

        self.sol(charCount, ans, i, totalChars, denominator)

        return ans[0] - 1 # Must exclude the all 0 choice case.