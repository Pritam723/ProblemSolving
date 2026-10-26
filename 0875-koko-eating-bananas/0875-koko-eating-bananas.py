class Solution:

    def isPossible(self, piles, m, h):
        i = 0
        j = len(piles) - 1
        t = 0
        while(i <= j):
            t = t + piles[i]//m + (1 if piles[i]%m else 0)

            if(t > h):
                return False

            i = i + 1
        return True


    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        s = 1
        e = sum(piles)

        k = e

        while(s <= e):
            m = s + (e-s)//2

            if(self.isPossible(piles, m, h)):
                # If possible means we can try a better k
                k = min(k, m)
                e = m - 1
            else:
                # So with m its not possible. Make it bigger.
                s = m + 1

        return k

