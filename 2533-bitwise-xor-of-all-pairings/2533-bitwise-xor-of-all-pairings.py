class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        m = len(nums1)
        n = len(nums2)

        x1,x2 = 0,0

        for num in nums1:
            x1 = x1 ^ num

        
        for num in nums2:
            x2 = x2 ^ num
        
        print(x1, x2)

        if((m%2 == 0) and (n%2 == 0)): return 0
        elif(m%2 == 0): return x1
        elif(n%2 == 0): return x2
        else: return x1 ^ x2
