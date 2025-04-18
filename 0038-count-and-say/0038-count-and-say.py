class Solution:
    def countAndSay(self, n: int) -> str:
        nStr = "1"
        i = 1
        while(i < n):
            encodedStr = ""
            m = len(nStr)
            j = 0

            prevCh = None
            count = 0
            while(j < m):

                if(prevCh is None or prevCh == nStr[j]):
                    count += 1
                else:
                    encodedStr = encodedStr + str(count) + prevCh  
                    count = 1
                prevCh = nStr[j]

                j = j + 1
            
            encodedStr = encodedStr + str(count) + prevCh  

            i = i + 1
            nStr = encodedStr

        return nStr