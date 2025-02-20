def bStrToInt(s, n):
    i = n-1
    mult = 1
    total = 0
    while(i >= 0):
        total = total + int(s[i])*mult
        mult = mult * 2
        i = i - 1
    return total


def intToBinary(num, n):
    # We need to give the binary in n digit.
    print(num)
    binaryStr = ""

    while(num != 0 or n > 0):
        if(num == 0):
            binaryStr = "0" + binaryStr

        else:
            binaryStr = str(num % 2) + binaryStr
        
        num = num//2
        n = n - 1

    return binaryStr

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:

        nums = sorted(nums)
        
        n = len(nums)

        # So, we may get 0 to 2^n - 1

        expectedNumber = 0
        
        for num in nums:
            numberReceived = bStrToInt(num, n)

            if(numberReceived == expectedNumber):
                expectedNumber = expectedNumber + 1
            else:
                break
        
        return intToBinary(expectedNumber, n)