class Solution:
    def maxFreeTime(self, event: int, start: List[int], end: List[int]) -> int:
        time=0
        free=[]
        ans=0
        for i in range(len(start)):
            free.append(start[i]-time)
            ans=max(ans,start[i]-time)
            time=end[i]
        free.append(event-time)
        left=0
        maxi=0
        right=0
        st=[0]*(len(free))
        for i in range(len(free)-1,0,-1):
            maxi=max(maxi,free[i])
            st[i]=maxi
        for i in range(len(free)-1):
            want=end[i]-start[i]
            if i>=1:
                left=max(left,free[i-1])
            if i+2<len(free):
                right=st[i+2]
            else:
                right=0
            if max(left,right)>=want:
                ans=max(ans,free[i]+free[i+1]+want)
            else:
                ans=max(ans,free[i]+free[i+1])
        return ans