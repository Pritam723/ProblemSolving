class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans = []
        i = 0
        for word in words:
            flag = False
            for ch in word:
                if(ch == x):
                    flag = True
                    break

            if(flag):
                ans.append(i)

            i = i + 1
        
        return ans