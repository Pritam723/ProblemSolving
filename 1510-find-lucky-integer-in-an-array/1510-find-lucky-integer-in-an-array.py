class Solution:
    def findLucky(self, arr: List[int]) -> int:
        dic={}
        l=[]
        for i in arr:
            if i not in dic:
                dic[i]=1
            else:
                dic[i]+=1
        for i in dic:
            if i==dic[i]:
                l.append(i)
        if(len(l)<1):
            return -1
        return max(l)