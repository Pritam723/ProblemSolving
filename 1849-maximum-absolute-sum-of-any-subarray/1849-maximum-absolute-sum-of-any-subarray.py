def maxSumSubarray(nums, n):
    i = 0

    meh = 0
    mss = 0

    while(i < n):
        val = nums[i]

        meh = max(val, meh + val)
        mss = max(mss, meh)

        i = i + 1

    return mss
def minSumSubarray(nums, n):
    i = 0

    meh = 0
    mss = 0

    while(i < n):
        val = nums[i]

        meh = min(val, meh + val)
        mss = min(mss, meh)

        # print(meh, mss)

        i = i + 1

    return mss
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        print(maxSumSubarray(nums, n),-minSumSubarray(nums, n))
        return max(maxSumSubarray(nums, n),-minSumSubarray(nums, n))
