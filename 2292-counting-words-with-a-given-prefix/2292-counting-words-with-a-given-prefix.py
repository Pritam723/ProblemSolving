class Solution:

    def isPrefix(self, word, m, pref, n):
        if(n > m): return False
        i = 0

        while(i < n):
            if(word[i] != pref[i]):
                return False
            i = i + 1

        return True
        

    def prefixCount(self, words: List[str], pref: str) -> int:
        n = len(pref)
        count = 0
        for word in words:
            m = len(word)

            if(self.isPrefix(word, m, pref, n)):
                count = count + 1
        return count