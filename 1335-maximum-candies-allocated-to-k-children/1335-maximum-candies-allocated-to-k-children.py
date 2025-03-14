def isPossible(candies, n, k, m):
    candyGivenTo = 0

    for c in candies:
        # So, with c candies, we will try to serve children.
        # we will give m to each.
        candyGivenTo += c//m
        if(candyGivenTo >= k): return True

    return False

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        n = len(candies)
        summ = sum(candies)

        maxCandies = summ // k

        if(summ < k): return 0

        s , e = 1, maxCandies

        ans = 0

        while(s <= e):
            m = s + (e-s)//2

            if(isPossible(candies, n, k, m)):
                # Checking if it is possible to distribute the candies
                # among k children so that each one gets m candies.
                # if yes, we can check for better.
                ans = m
                s = m + 1
            else:
                # If not possible, we check with smaller number.
                e = m - 1

        return ans