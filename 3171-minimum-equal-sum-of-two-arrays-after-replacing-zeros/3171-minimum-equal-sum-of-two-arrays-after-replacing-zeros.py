def getMinMax(nums):
    zeroCount = 0
    summ = 0
    for num in nums:
        if(num == 0):
            zeroCount += 1
        summ = summ + num

    if(zeroCount == 0):
        return summ, summ

    return summ + zeroCount, 10**12


class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        minA, maxA = getMinMax(nums1)
        minB, maxB = getMinMax(nums2)

        maxOfMins = max(minA, minB)
        # Now this should be in both the ranges.

        if((minA <= maxOfMins and maxOfMins <= maxA) and (minB <= maxOfMins and maxOfMins <= maxB)):
            return maxOfMins

        return -1
