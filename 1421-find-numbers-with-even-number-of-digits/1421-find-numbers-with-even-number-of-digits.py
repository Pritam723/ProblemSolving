class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            l = len(str(num))
            if(l % 2 == 0):
                count += 1

        return count