class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.counter1 = Counter(nums1)
        self.counter2 = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        old_value = self.nums2[index]
        new_value = old_value + val
        self.counter2[old_value] -= 1
        if self.counter2[old_value] == 0:
            del self.counter2[old_value]
        self.nums2[index] = new_value
        self.counter2[new_value] += 1

    def count(self, tot: int) -> int:
        total = 0
        for num in self.counter1:
            complement = tot - num
            total += self.counter1[num] * self.counter2.get(complement, 0)
        return total

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)