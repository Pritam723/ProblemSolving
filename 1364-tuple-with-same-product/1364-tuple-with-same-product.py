class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        productMap = {}
        n = len(nums)

        for i in range(n):
            for j in range(i+1, n):
                product = nums[i]*nums[j]
                if(productMap.get(product) is None):
                    productMap[product] = 1
                else:
                    productMap[product] = productMap[product] + 1
        
        ans = 0
        for key in productMap:
            val = productMap[key]
            if(val > 1):
                ans = ans + 4*(val)*(val-1)
        
        return ans
