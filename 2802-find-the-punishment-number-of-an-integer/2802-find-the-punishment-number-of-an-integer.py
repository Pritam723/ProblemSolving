class Solution:
    def sol(self, sq, target, L):
        if(target < 0): return False
        if(int(sq) == target): return True
        
        flag = False

        for i in range(1, L):
            leftStr = sq[0 : i]
            rightStr = sq[i :]

            newTarget = target - int(leftStr)

            flag = flag or self.sol(rightStr, newTarget, L-i)
            if(flag): break

        return flag


    def punishmentNumber(self, n: int) -> int:
        ans = 0

        for i in range(1, n+1):
            sq = str(i*i)
            L = len(sq)

            if(self.sol(sq, i, L)):
                ans = ans + (i*i)

        return ans