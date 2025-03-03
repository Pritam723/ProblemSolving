class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        ans = [0]*n

        less = 0
        more = 0 
        
        for item in nums:
            if(item < pivot):
                less = less + 1
            elif(item > pivot):
                more = more + 1
        
        i = 0
        j = less
        k = n - more

        print(i, j, k)

        for idx in range(n):
            item = nums[idx]

            if(item < pivot):
                ans[i] = item
                i = i + 1
            elif(item > pivot):
                ans[k] = item
                k = k + 1
            else:
                ans[j] = item
                j = j + 1

        return ans
