class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        ans = []
        nums.sort()
        L = len(nums)
        print(nums)
        for i in range(L//3):
            startIdx = i*3
            endIdx = i*3 + 2

            if(nums[endIdx] - nums[startIdx] > k):
                return []
            
            pa = nums[startIdx: endIdx + 1].copy()
            ans.append(pa)

        return ans