class Solution:
    def twoSum(self, nums: list[int], j: int, n: int, t: int) -> list[list[int]]:

        if(j == n): return []

        res = []
        k = n - 1
        # WKT its already sorted. Careful to skip duplicate.
        
        lastSeen = nums[j] - 1
        
        while(j < k):

            if(nums[j] + nums[k] == t and nums[j] != lastSeen):
                res.append([nums[j], nums[k]])
                lastSeen = nums[j]
                j = j + 1
                k = k - 1
            elif(nums[j] + nums[k] < t):
                j = j + 1
            else:
                k = k - 1

        return res


        return res
    
    
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()
        n = len(nums)
        # print(nums)
        target = 0
        lastSeen = nums[0] - 1

        for i,num in enumerate(nums):
            print(i, num)

            if(nums[i] == lastSeen):
                i = i + 1
                continue

            lastSeen = nums[i]

            t = target - num

            getTwoSumList = self.twoSum(nums, i+1, n, t)

            if(len(getTwoSumList)) > 0:
                print(f'for {num} we got {getTwoSumList}')
                res.extend([[num] + item for item in getTwoSumList])


        return res