class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        # See the hint. Very Important. Different way to solve the problem.
        # See we need to understand the 3 digit even numbers will be from 100 to 998.
        ans = []
        mp = defaultdict(int)

        for digit in digits:
            mp[digit] = mp[digit] + 1

        for num in range(100, 999, 2):
            numStr = str(num)

            numMP = defaultdict(int)

            for ch in numStr:
                chInt = int(ch)
                numMP[chInt] = numMP[chInt] + 1

            flag = True
            for key in numMP:
                if(numMP[key] > mp[key]):
                    flag = False
                    break
            
            if(flag == True):
                ans.append(num)

        return ans