class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
      num_unique, res = len(set(nums)), 0
      for i in range(len(nums)):
        vals = set()
        for j in range(i, len(nums)):
          vals.add(nums[j])
          if len(vals) == num_unique:
            res += len(nums) - j
            break
      return res
