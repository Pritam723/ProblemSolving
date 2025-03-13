def isZeroArray(nums, n, queries, m):
    # Need to check if after first m queries our actual Array becomes all <= 0
    prefixSum = [0]*n

    i = 0
    while(i < m):
        query = queries[i]
        
        l = query[0]
        r = query[1]
        val = query[2]

        prefixSum[l] = prefixSum[l] + val

        if(r + 1 < n):
            prefixSum[r + 1] = prefixSum[r + 1] - val

        i = i + 1 
    

    print(prefixSum)

    i = 0
    summ = 0
    for i in range(n):
        prefixSum[i] = summ + prefixSum[i]
        summ = prefixSum[i]

        if(nums[i] - prefixSum[i] > 0):
            return False
    



    return True
    


class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        # Difference Array Technique after Binary Search.
        n = len(nums)

        L = len(queries)

        s, e = 0, L

        k = None

        while(s <= e):
            m = s + (e-s)//2

            # m is basically how many number of query we are using. 

            print(f"Try with {m}")

            if(isZeroArray(nums, n, queries, m)):
                # If possible. It is a potential ans.
                k = m
                # And we can look for better.
                e = m - 1
            else:
                s = m + 1
        
        if(k == None): return -1
        return k