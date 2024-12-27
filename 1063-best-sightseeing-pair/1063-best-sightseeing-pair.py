class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        meh = -10**9 - 1
        mssp = -10**9 - 1

        n = len(values)
        i = 1

        while(i < n):
            op1 = meh - values[i-1] + values[i] - 1
            op2 = values[i] + values[i-1] - 1

            meh = max(op1, op2)
            mssp = max(meh, mssp)

            i = i + 1

        return mssp