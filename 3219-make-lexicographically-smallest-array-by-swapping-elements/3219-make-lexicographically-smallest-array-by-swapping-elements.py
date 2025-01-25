from collections import deque
class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        # Refer explanation: https://www.youtube.com/watch?v=-FGl6dzPexY
        
        numsCopy = nums.copy()

        n = len(nums)
        nums.sort()

        groups = []
        prev = nums[0] + limit + 1 # Making it out of limit
        groupNo = -1
        numMap = {}

        for i in range(n):
            if(abs(nums[i] - prev) > limit):
                dq = deque([nums[i]])
                groups.append(dq)
                groupNo = groupNo + 1
            else:
                groups[groupNo].append(nums[i])

            prev = nums[i]
            numMap[nums[i]] = groupNo

        print(numMap)

        for i in range(n):
            groupNo = numMap[numsCopy[i]]
            val = groups[groupNo].popleft()
            # print(val)
            numsCopy[i] = val

        return numsCopy