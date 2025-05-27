class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        n1,m1 = 0,0
        for i in range(1,n+1):
            if i%m == 0:
                n1 += i
            else:
                m1 += i
        return m1-n1