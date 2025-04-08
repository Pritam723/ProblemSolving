class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        count={}
        n=len(nums)
        res=0
        for i in range(n-1,-1,-1):
            if nums[i] not in count:
                count[nums[i]]=1
            else:
                return (i//3+1)
        return 0