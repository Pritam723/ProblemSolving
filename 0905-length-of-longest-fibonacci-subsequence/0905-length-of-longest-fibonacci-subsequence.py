class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        # First let's see how to do it in Brute Force.
        # See, A Sequence will always depend on the First 2 numbers.
        # So, with n items we have O(n^2) pairs. And for a pair we
        # can check the length is O(n). So, we get O(n^3) which is TLE.
        # How to do better? See, if we have 1,2,3,5,8,13,21,34,...
        # So, we can say that LengthOfFS(Starting with 1,2) = 2 + LengthOfFS(Starting with 3, 5)
        # Base case? See, All are distinct. So, if MAP[5] = False, return 1, if MAP[3] is also
        # False, we return 0. If both True we return 2 + LFS(Starting with 8, 13).
        maxLength = 2
        n = len(arr)
        mp = {}
        for i in range(n):
            mp[arr[i]] = i # Storing the index. Because item can be 10^9 will give MLE.

        LFS = []
        for i in range(n):
            singleRow = [0]*n
            singleRow[n-1] = 2
            
            LFS.append(singleRow.copy())
        # print(LFS)

        # LFS[2][3] = 8

        r = n - 3

        while(r >= 0):
            c = r + 1

            while(c < n-1):

                # print(r,c)
                
                # We want to calculate LFS[r][c]
                # Now, first check arr[r], arr[c]
                val1 = arr[r]
                val2 = arr[c]

                # Now predict next 2 values.
                val3 = val1 + val2
                val4 = val2 + val3

                # Now, if both exists.
                if(mp.get(val3) and mp.get(val4)):
                    idx1 = mp.get(val3)
                    idx2 = mp.get(val4)
                    # idx1 will be < idx2 naturally.
                    # So, r is idx1, c is idx2 
                    LFS[r][c] = 2 + LFS[idx1][idx2]
                elif(mp.get(val3)):
                    LFS[r][c] = 2 + 1
                else:
                    LFS[r][c] = 2

                maxLength = max(maxLength, LFS[r][c])

                c = c + 1

            r = r - 1

        # print(LFS)

        if(maxLength == 2): return 0
        return maxLength