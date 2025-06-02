class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0
        
        ret = 1  # first child
        up = down = peak = 0

        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:  # uphill
                up += 1
                peak = up
                down = 0
                ret += 1 + up
            elif ratings[i] == ratings[i - 1]:  # flat
                up = down = peak = 0
                ret += 1
            else:  # downhill
                up = 0
                down += 1
                ret += 1 + down - (1 if peak >= down else 0)

        return ret