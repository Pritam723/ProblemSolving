class Solution:

    def toBinary(self, ansStr):
        n = len(ansStr)
        dec = 0
        d = 1
        i = n-1

        while(i >= 0):
            dec = dec + int(ansStr[i])*d
            i = i - 1
            d = d*2

        return dec



    def binaryStr(self, n):
        bStr = ""

        while(n):
            bStr = str(n & 1) + bStr
            n = n >> 1
        
        return(bStr)

    def minimizeXor(self, num1: int, num2: int) -> int:
        
        b1 = 0
        n = num1
        while(n):
            n = n & (n-1)
            b1 += 1 
        
        b2 = 0
        n = num2
        while(n):
            n = n & (n-1)
            b2 += 1

        if(b1 == b2): return num1

        num1Str = self.binaryStr(num1)
        print(num1Str, b2)

        m = len(num1Str)
        i = 0

        ansStr = ['0']*m
        if(b2 >= m): return pow(2, b2) - 1

        # It means b2 (No. of bits) is < m

        while(i < m and b2 > 0):
            if(num1Str[i] == '0'):
                i = i + 1
            else:
                ansStr[i] = '1'
                i = i + 1
                b2 = b2 - 1

        # There might still be b2 left.
        i = m-1
        while(b2 > 0):
            if(ansStr[i] == '1'):
                i = i - 1
            else:
                ansStr[i] = '1'
                b2 = b2 - 1

        ans = self.toBinary(ansStr)

        return ans