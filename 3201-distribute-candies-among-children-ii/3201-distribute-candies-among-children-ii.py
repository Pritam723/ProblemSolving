def fact(x):
    res = 1
    for i in range(1, x+1):
        res = res * i
    return res


class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        # S.N. Dey roll dice and get number problem.
        # Here we are rolling 3 dice with numbers 0,1,2,...,limit.
        # We want to get n.
        L = limit
        coefficientMap = {0 : 1, L + 1: -3, 2*L+2: 3, 3*L+3: -1}

        ans = 0
        for c in coefficientMap:
            if(c > n):
                break
            rem = n - c

            # op1 = fact(3 + rem - 1)
            # op2 = fact(rem)

            # pa = op1 // op2

            pa = (rem+1)*(rem+2) // 2

            ans = ans + pa*coefficientMap[c]

        return ans
        
