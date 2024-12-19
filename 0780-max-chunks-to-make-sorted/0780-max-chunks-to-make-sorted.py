def isRangeCovered(visited, minVal, maxVal):
    i = minVal
    while(i <= maxVal):
        if(visited[i] == False): return False
        i = i + 1
    return True

class Solution:


    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        visited = [False]*n

        minVal = 0
        maxVal = -10**9 - 1
        l = 0

        count = 0

        while(l < n):
            val = arr[l]
            
            visited[val] = True

            maxVal = max(val, maxVal)

            if(isRangeCovered(visited, minVal, maxVal)):
                count = count + 1
                minVal = l + 1
                maxVal = -10**9 - 1
                l = l + 1
            else:
                l = l + 1

        return count

