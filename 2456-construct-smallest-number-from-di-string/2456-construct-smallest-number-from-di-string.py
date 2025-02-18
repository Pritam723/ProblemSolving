class Solution:
    def sol(self, pattern, i, n, visited, ans, num):
        if(i == -1):
            # So, this is first character. We have free choice.
            for _j in range(1,10):
                num = str(_j)
                visited[_j] = True
                self.sol(pattern, i + 1, n, visited, ans, num)
                visited[_j] = False
            
        if(i == n): # So, we have built num already.
            num_int = int(num)
            ans[0] = min(num_int, ans[0])
            return
        
        # Otherwise we are at 0 <= i < n
        indicator = pattern[i]
        # Now if we are at i = 0, we are basically deciding for num[i+1]
        # by looking at num[i] and indicator.
        prev = int(num[i])

        if(indicator == "I"):
            for _j in range(prev + 1, 10):
                if(visited[_j] == True): continue
                num = num + str(_j)
                visited[_j] = True
                self.sol(pattern, i + 1, n, visited, ans, num)
                num = num[:-1]
                visited[_j] = False

        else: # So, it is "D"
            for _j in range(1, prev):
                if(visited[_j] == True): continue
                num = num + str(_j)
                visited[_j] = True
                self.sol(pattern, i + 1, n, visited, ans, num)
                num = num[:-1]
                visited[_j] = False

    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        visited = [False]*10 # Use index 1 to 9
        # num can have 9 digits at max.
        ans = [10**10]

        num = ""
        i = -1

        self.sol(pattern, i, n, visited, ans, num)

        # num = num + "1"
        # num = num[:-1]

        return str(ans[0])

