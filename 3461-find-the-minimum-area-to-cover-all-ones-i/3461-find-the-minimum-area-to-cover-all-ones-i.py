class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        r=len(grid)
        c=len(grid[0])
        rs=rl=-1
        cs=cl=-1
        for i in range(r):
            for j in range(c):
                if grid[i][j]==1:
                    if rs==-1:
                        rs=i
                    rl=i
                    if cs==-1:
                        cs=j
                    else:
                        cs=min(cs,j)
                    cl=max(cl,j)
        b=(rl-rs)+1
        l=(cl-cs)+1
        return b*l