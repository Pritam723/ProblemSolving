class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        n = len(words)
        ans = []
        # words.sort(reverse=True)

        print(words)

        for i in range(n):
            word1 = words[i]
            # print(word1)
            j = 0
            while(j < i):
                word2 = words[j]
                # print(word2)
                if(word1 in word2):
                    # print(word1 + " is ss of " + word2)
                    ans.append(word1)
                    # break
                if(word2 in word1):
                    ans.append(word2)
                    # break
                j = j + 1
        
        ans = list(set(ans))
        return ans