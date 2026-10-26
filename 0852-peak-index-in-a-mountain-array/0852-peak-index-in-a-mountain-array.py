class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:


        # 0, 10, 5, 2
        # - guaranteed mountain so cant be 0,1,2,3. So answer must be b/w 0, n-2
        # /\

        s = 0
        e = len(arr) - 2
        ans = -1
        while(s <= e):
            m = s + (e-s)//2
            _curr = arr[m]
            _next = arr[m+1]

            if(_next < _curr):
                # Potential ans, but can be better right?
                # I might be checking some element here: 6,5,4,3,2
                # even if curr is at 6, thats also fine to do e = m - 1
                ans = m
                e = m - 1
            else:
                # not checking equal case as because no repeat elem.
                s = m + 1

        return ans




