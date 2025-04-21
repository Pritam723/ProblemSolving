class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        # Find the max and min considering start x = 0
        maxi = 0
        mini = 0

        n = len(differences)
        x = 0

        for difference in differences:
            x = x + difference
            maxi = max(x, maxi)
            mini = min(x, mini)

        print(mini, maxi)
        # Now, say low = -4 and high = 5
        # mini = -1 and maxi = 5
        # So, surely in worst case we can start from x = -3
        # And at higher side we can start from x = 0.
        # So, # of possibilities are 0-(-3)+1 = 4.

        minStart = lower - mini
        maxStart = upper - maxi

        print(minStart, maxStart)

        return max(maxStart - minStart + 1, 0)    
