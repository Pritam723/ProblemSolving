class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        arr = []
        remainingSum = ((len(rolls) + n)*mean) - sum(rolls)
        while n > 0:
            if remainingSum < n or remainingSum > 6*n:
                return []
            else:
                val = remainingSum//n
                arr.append(val)
                remainingSum = remainingSum - val
                n = n-1
        return arr
        