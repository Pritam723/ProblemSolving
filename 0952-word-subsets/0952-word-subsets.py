class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        # Surely a brute force would take O(n)*O(n)*O(10) > 10^8 so TLE.
        # A nice trick is to take all strings of words2 first and make
        # a count map which will haveper word max occurance of each character.
        # Ex. If we have ["lee", "lloc"]. So, surely to be universal, a string
        # in words1 must have atleast 2 'l', atleast 2 'e' etc.

        charFreq = [0]*26

        for word in words2:
            currwordFreq = [0]*26 
            for ch in word:
                chIdx = ord(ch) - ord('a')
                currwordFreq[chIdx] += 1
                charFreq[chIdx] = max(charFreq[chIdx], currwordFreq[chIdx])
        
        print(charFreq)
        ans = []

        for word in words1:
            currwordFreq = [0]*26
            for ch in word:
                chIdx = ord(ch) - ord('a')
                currwordFreq[chIdx] += 1

            isUniversal = True
            for i in range(26):
                if(currwordFreq[i] < charFreq[i]):
                    isUniversal = False
                    break

            if(isUniversal): ans.append(word)

        return ans