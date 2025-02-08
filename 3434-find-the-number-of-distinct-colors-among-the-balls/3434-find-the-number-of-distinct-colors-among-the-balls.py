class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        # O(limit) gives TLE.
        n = len(queries)
        
        indexVisit = {}
        colorFreq = {}

        distinctColors = 0

        ans = [0]*n

        for i in range(n):
            idx = queries[i][0]
            color = queries[i][1]

            if(indexVisit.get(idx) is None):
                
                # Color it first
                indexVisit[idx] = color

                if((colorFreq.get(color) is None) or (colorFreq[color] == 0)):
                    colorFreq[color] = 1
                    distinctColors = distinctColors + 1
                else:
                    colorFreq[color] = colorFreq[color] + 1
                    # But do not increase distinctColors.
            else:
                # So, we are coloring the index again. Remove the old color first.
                oldColor = indexVisit[idx]
                # Color it with new.
                indexVisit[idx] = color

                colorFreq[oldColor] = colorFreq[oldColor] - 1
                if(colorFreq[oldColor] == 0):  
                    distinctColors = distinctColors - 1
                
                if((colorFreq.get(color) is None) or (colorFreq[color] == 0)):
                    colorFreq[color] = 1
                    distinctColors = distinctColors + 1
                else:
                    colorFreq[color] = colorFreq[color] + 1
            
            ans[i] = distinctColors

        return ans

