class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        l=[]
        l.append(startTime[0]-0)
        b=endTime[0]
        for i in range(1,len(startTime)):
            l.append(startTime[i]-b)
            b=endTime[i]
        l.append(eventTime-b)
        k+=1
        m=sum(l[:k])
        q=m
        for i in range(k,len(l)):
            m=m-l[i-k]+l[i]
            q=max(m,q)

        return q
        