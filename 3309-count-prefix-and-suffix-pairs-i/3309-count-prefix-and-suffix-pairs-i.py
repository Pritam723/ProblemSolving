class Solution:
    def isPrefixAndSuffix(self, str1, str2):
        m1 = len(str1)
        m2 = len(str2)

        if(m1 > m2): return False

        i = 0
        while(i < m1):
            if(str1[i] != str2[i]): return False
            i = i + 1

        i = 0
        while(i < m1):
            if(str1[m1-1-i] != str2[m2-1-i]): return False
            i = i + 1

        return True



    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        count = 0
        for i in range(n):
            str1 = words[i]

            j = i+1
            while(j < n):
                str2 = words[j]

                if(self.isPrefixAndSuffix(str1, str2)):
                    count = count + 1
                j = j + 1

        return count