class Solution:
    def reverse(self, x: int) -> int:
        # NOTE. In C++ Sign of % is sign of numerator
        # In Python it is Sign of divisor.
        ans = 0
        mult = 1 if x >= 0 else -1
        
        x = abs(x)

        INT_MAX = pow(2,31) - 1 # 2147483647 = 214748364*10 + 7
        INT_MIN = -pow(2,31) # -2147483648 = -214748364*10 - 8

        while(x != 0):
            q = x%10

            # Before I multiply ans with 10, I need to check it,
            # check both +ve and -ve cases.

            if(mult == 1 and ans > INT_MAX//10): return 0
            if(mult == 1 and ans == INT_MAX//10 and q > 7): return 0

            if(mult == -1 and ans > INT_MAX//10): return 0
            if(mult == -1 and ans == INT_MAX//10 and q > 8): return 0


            ans = 10*ans + q
            x = x//10


        return mult*ans