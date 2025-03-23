def heapSort(nums, n):
    sz = n

    while(sz > 0):
        nums[0], nums[sz-1] = nums[sz-1], nums[0]
        sz = sz - 1
        maxHeapify(nums, sz, 0)


def buildMaxHeap(nums, n):
    nonLeaf = n//2 - 1
    i = nonLeaf

    while(i >= 0):
        maxHeapify(nums, n, i)
        i = i - 1

def maxHeapify(nums, n, i):
    maxIdx = i

    while(i < n):
        l = 2*i + 1
        r = 2*i + 2

        if(l < n and nums[l] > nums[maxIdx]):
            maxIdx = l

        if(r < n and nums[r] > nums[maxIdx]):
            maxIdx = r

        if(maxIdx == i):
            break
        
        nums[i], nums[maxIdx] = nums[maxIdx], nums[i]
        i = maxIdx

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        buildMaxHeap(nums, n)
        heapSort(nums, n)

        return nums