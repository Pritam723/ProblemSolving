class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        
        numCount = {}
        
        for i in range(n):
            nums[i] = nums[i] - i

            if(numCount.get(nums[i]) is None):
                numCount[nums[i]] = 1
            else:
                numCount[nums[i]] = numCount[nums[i]] + 1

        print(nums)

        totalPairs = int(n*(n-1)/2)
        goodPairs = 0

        for key in numCount:
            count = numCount[key]
            goodPairs = goodPairs + int(count*(count-1)/2)

        return totalPairs - goodPairs