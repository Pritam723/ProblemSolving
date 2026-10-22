class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        # [4,3,2,7,8,2,3,1]
        ans = []

        n = len(nums)
        i = 0

        while(i < n):
            num = abs(nums[i])
            checkIndex = num - 1

            if(nums[checkIndex] < 0):
                ans.append(num)
            else:
                nums[checkIndex] = -nums[checkIndex]
            i = i + 1


        return ans