from collections import deque
class Solution:
    def clearDigits(self, s: str) -> str:
        n = len(s)
        ans = ""
        st = deque([])

        for i in range(n):
            ch = s[i]
            if(ch >= '0' and ch <= '9'):
                st.pop()
            else:
                st.append(ch)

        ans = ''.join(st)
        return ans

