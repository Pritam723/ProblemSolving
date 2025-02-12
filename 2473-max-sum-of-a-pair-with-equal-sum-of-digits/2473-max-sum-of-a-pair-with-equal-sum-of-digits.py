class Solution:
    def getMax2OutOf3(self,a,b,c):

        if(a is None): return [b,c]
        if(b is None): return [a,c]
        if(c is None): return [a,b]


        if(a > b):
            return [a, max(b,c)]
        if(b > c):
            return [b, max(c,a)]
        if(c > a):
            return [c, max(a,b)]

    def maximumSum(self, nums: List[int]) -> int:
        mp = {}
        n = len(nums)

        ans = -1

        for i in range(n):
            num = nums[i]
            num_str = str(num)
            m = len(num_str)
            summ = 0
            for j in range(m):
                summ = summ + int(num_str[j])
            # print("sum is " + str(summ))
            if(mp.get(summ) is None):
                mp[summ] = [num, None]
            else:
                a = mp[summ][0]
                b = mp[summ][1]
                c = num

                mp[summ] = self.getMax2OutOf3(a,b,c)
                ans = max(ans, mp[summ][0] + mp[summ][1])

        return ans