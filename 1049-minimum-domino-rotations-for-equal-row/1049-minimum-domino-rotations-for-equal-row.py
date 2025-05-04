class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        possible = set()
        top_cnt, btm_cnt = [0] * 7, [0] * 7 # To store dice val 1 ~ 6
        possible.update((tops[0], bottoms[0]))
        ans = float("inf")

        for i in range(len(tops)):
            possible &= {tops[i], bottoms[i]} # Keep updating possible vals
            if tops[i] in possible and tops[i] != bottoms[i]:
                btm_cnt[tops[i]] += 1
            if bottoms[i] in possible and tops[i] != bottoms[i]:
                top_cnt[bottoms[i]] += 1

        for i in possible:
            ans = min(top_cnt[i], btm_cnt[i])

        return ans if possible else -1