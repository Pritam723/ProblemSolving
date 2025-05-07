class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])
        pq = [(0,0,0)] # (time, x,y)
        visited = [[False for _ in range(m)] for _ in range(n)]
        visited[0][0] = True
        while pq:
            time, x,y = heapq.heappop(pq)
            #print("time={}, x,y={},{}".format(time,x,y))
            if (x,y) == (n-1,m-1):
                return time
            
            # Explore the neighbors
            for adjX, adjY in [(x-1,y), (x+1,y), (x,y-1), (x,y+1)]:
                if adjX >= 0 and adjX < n and adjY >= 0 and adjY < m and not visited[adjX][adjY]:
                    adjTime = moveTime[adjX][adjY]
                    # The time it takes depends on how much time it takes you to get here or when that spot is available
                    adjTime = max(time, adjTime) + 1
                    heappush(pq, (adjTime, adjX,adjY))
                    visited[adjX][adjY] = True
                    #print("Finished moving from {},{} to {},{} at t={}".format(x,y, adjX,adjY, adjTime))