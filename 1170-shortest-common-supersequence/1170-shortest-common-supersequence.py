def sol(str1, str2, m, n, caching):
    # Starting from 0,0 to m,n. So, guess the direction of BU
    
    for j in range(n):
        caching[1][j] = str2[j :]
    
    i = m - 1
    # j = n
    # print(m,n)
    while i >= 0:
        caching[0][n] = str1[i : ]
        j = n - 1
        while j >= 0:
        
            ch1 = str1[i]
            ch2 = str2[j]
            if(ch1 == ch2): caching[0][j] = ch1 + caching[1][j + 1]
            else:
                op1 = ch1 + caching[1][j]
                op2 = ch2 + caching[0][j + 1]

                if(len(op1) < len(op2)):
                    caching[0][j] = op1
                else:
                    caching[0][j] = op2

            j = j - 1
        
        caching[1] = caching[0].copy()

        i = i - 1
    
    return caching[0][0]

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m = len(str1)
        n = len(str2)

        caching = []

        for i in range(2):
            singleRow = [""]*(n+1)
            caching.append(singleRow.copy())
        
        ans = sol(str1, str2, m, n, caching)

        return ans