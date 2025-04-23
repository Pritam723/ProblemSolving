from collections import defaultdict
class Solution:
    def countLargestGroup(self, n: int) -> int:
        mp = defaultdict(int)
        maxSize = 0
        for i in range(1, n+1):
            numStr = str(i)
            summ = 0
            for ch in numStr:
                summ = summ + int(ch)

            mp[summ] = mp[summ] + 1
            maxSize = max(maxSize, mp[summ])
        
        ans = 0
        for key in mp:
            if(mp[key] == maxSize):
                ans = ans + 1
                
        return ans 