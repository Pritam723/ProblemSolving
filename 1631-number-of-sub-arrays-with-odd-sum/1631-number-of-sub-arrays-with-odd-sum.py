class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        m = 10**9 + 7

        n = len(arr)
        ans = 0

        sos = 0
        ses = 0

        if(arr[0] % 2 == 0): ses = 1
        else: sos = 1

        print(ses, sos)
        ans = sos

        for i in range(1, n):
            val = arr[i]
            if(val % 2 == 0):
                n_ses = ses + 1
                n_sos = sos
            else:
                n_ses = sos
                n_sos = ses + 1
            
            print(n_ses, n_sos)
            
            ses = n_ses
            sos = n_sos

            ans = ((ans % m) + (sos % m)) % m

        return ans