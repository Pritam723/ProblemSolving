class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        my_dict = {}
        for ch in word:
            my_dict[ch] = my_dict.get(ch, 0) + 1

        list1 = sorted(my_dict.values())
        M = len(list1)
        mini = float('inf')

        for i in range(M):
            base = list1[i]
            temp = 0
            for j in range(M):
                if list1[j] < base:
                    temp += list1[j]
                elif list1[j] > base + k:
                    temp += list1[j] - (base + k)  
            mini = min(mini, temp)

        return mini