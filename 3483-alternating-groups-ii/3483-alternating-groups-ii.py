class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        colors = colors + colors
        print(colors)

        ans = 0

        l = 0

        while(l < n):
            r = l + 1
            while(r <= n + k - 2):
                if(colors[r] == colors[r-1]):
                    break
                r = r + 1
            
            if(r - l >= k):
                ans = ans + r - l - k + 1

            
            l = r


        return ans