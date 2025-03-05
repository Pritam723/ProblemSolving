class Solution:
    def coloredCells(self, n: int) -> int:
        if(n == 1): return 1

        base = 1
        total = 1

        i = 1
        while(i < n):
            total = total + 2 * base + 2
            base = base + 2
            i = i + 1

        return total