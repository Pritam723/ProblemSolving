class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        m = len(nums1)
        n = len(nums2)

        i = 0
        j = 0

        ans = []

        while((i < m) and (j < n)):
            item1 = nums1[i]
            item2 = nums2[j]

            if(item1[0] == item2[0]):
                ans.append([item1[0], item1[1] + item2[1]])
                i += 1
                j += 1
            elif(item1[0] < item2[0]):
                ans.append([item1[0], item1[1]])
                i += 1
            else:
                ans.append([item2[0], item2[1]])
                j += 1

        while(i < m):
            item1 = nums1[i]
            ans.append([item1[0], item1[1]])
            i += 1

        while(j < n):
            item2 = nums2[j]
            ans.append([item2[0], item2[1]])
            j += 1

        return ans