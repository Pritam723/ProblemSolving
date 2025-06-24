import math

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        left = 0
        right = 0
        result = []

        while right < len(nums) and left < len(nums):
            if nums[right] != key:
                right += 1
            else:
                if math.fabs(left - right) <= k:
                    result.append(left)

                if math.fabs(left - right) > k and left > right:
                    right += 1
                else:
                    left += 1

        return result