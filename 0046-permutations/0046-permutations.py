def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def sol(nums, n, i, ans):
    if(i == n):
        ans.append(nums.copy())
        return

    for j in range(i, n):
        swap(nums, i, j)
        sol(nums, n, i + 1, ans)
        swap(nums, i, j) # Swap back.
        

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        i = 0
        ans = []
        sol(nums, n, i, ans)
        return ans