class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Either array starts with 1 or 0.
        n = len(derived)
        if(n == 1): return not derived[0]
        # isPossible = False

        start = 1
        end = 1 ^ derived[0]

        i = 2

        while(i < n):
            end = end ^ derived[i-1]
            i = i + 1

        print(start, end)

        if(start ^ end == derived[n-1]): return True
        return False