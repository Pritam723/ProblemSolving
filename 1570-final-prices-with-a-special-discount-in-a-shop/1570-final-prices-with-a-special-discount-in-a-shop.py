from collections import deque
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        NSI = [n]*n

        st = deque([])
        # st.append(n)

        i = n-1

        while(i >= 0):
            val = prices[i]
            while(len(st) > 0 and prices[st[-1]] > val): st.pop()
            # We are here means either st is empty or we have
            # an element on top which is <= val.
            if(len(st) == 0): NSI[i] = n
            else: NSI[i] = st[-1]

            st.append(i)

            i = i - 1

        print(NSI)

        for i, item in enumerate(prices):
            if(NSI[i] == n): continue
            else: 
                discount = prices[NSI[i]]
                prices[i] = item - discount

        return prices