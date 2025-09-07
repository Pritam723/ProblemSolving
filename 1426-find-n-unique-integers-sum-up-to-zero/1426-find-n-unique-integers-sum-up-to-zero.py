class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [] 
        i = 1 
        if n % 2 == 0:
            j = 0
        else:
            j = 1
            ans.append(0)
        while j < n:
            ans.append(i)
            ans.append(-i)
            i += 1
            j += 2
        return ans