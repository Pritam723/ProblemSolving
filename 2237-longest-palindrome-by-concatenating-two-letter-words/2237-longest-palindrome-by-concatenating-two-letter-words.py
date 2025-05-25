class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        d = defaultdict(int)
        ans = f = 0
        for w in words:
            d[w] += 1
        for k, v in d.items():
            x,y = k
            if x == y:
                if v&1 and not f: f = 2
                ans += 2*(v//2)
            elif y+x in d:
                ans += min(d[k], d[y+x])
        return 2*ans+f