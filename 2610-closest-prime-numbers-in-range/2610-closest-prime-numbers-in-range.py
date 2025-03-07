class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        ans = [-1,-1]
        sieve = [True]*(right+1)
        sieve[0] = sieve[1] = False

        for i in range(2, right+1):
            if(i*i > right+1):
                break
            if(sieve[i] == False):
                continue
            # So, we got a prime.
            j = i*i
            while(j < right + 1):
                sieve[j] = False
                j = j + i

        prev = None
        curr = None
        minGap = 10**10
        for i in range(left, right+1):
            if(sieve[i] == True):
                if(prev is None):
                    prev = i
                elif(curr is None):
                    curr = i
                    if(curr-prev < minGap): # Not <=
                        minGap = min(minGap, curr-prev)
                        ans = [prev, curr]
                else:
                    # So, both are not None
                    prev = curr
                    curr = i
                    if(curr-prev < minGap): # Not <=
                        minGap = min(minGap, curr-prev)
                        ans = [prev, curr]

        # print(sieve)

        return ans