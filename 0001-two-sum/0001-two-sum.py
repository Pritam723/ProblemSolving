from collections import defaultdict
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        ans = [-1,-1]
        n = len(nums)

        checkMap = defaultdict(lambda: -1)
        print(checkMap[3])
        i = 0
        while(i < n):
            num = nums[i]
            if checkMap[target - num] != -1:
                ans = [i, checkMap[target - num]]
                break

            checkMap[num] = i
            
            
            i = i + 1


        return ans