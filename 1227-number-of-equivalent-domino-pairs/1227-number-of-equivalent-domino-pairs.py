class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d={}
        cnt=0
        for i,j in dominoes:
            key=(min(i,j),max(i,j))
            if key in d:
                cnt += d[key]
                d[key]+=1
            else:
                d[key]=1
        return cnt