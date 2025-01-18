from collections import deque

class Solution:
    def addNeighbours(self, adjList, m, n, r, c, newR, newC, dist):
        cellNo = r*n + c
        newCellNo = newR*n + newC
        if(newR < 0 or newR >= m): return
        if(newC < 0 or newC >= n): return

        if(adjList.get(cellNo) is None): adjList[cellNo] = []
        adjList[cellNo].append((newCellNo, dist))
        return

    def minCost(self, grid: List[List[int]]) -> int:
        # We consider each cell as a node. So, instead of
        # (r,c) we can give them number r*n + c. Now, a cell has
        # 4 other neighbour cells. Distance to them is either 0 or 1.
        m = len(grid)
        n = len(grid[0])

        dirs = [[0,1,1],[0,-1,2],[1,0,3],[-1,0,4]]

        adjList = {}

        for r in range(m):
            for c in range(n):
                # cellNo = r*n + c
                arrow = grid[r][c]

                for direction in dirs:
                    newR = r + direction[0]
                    newC = c + direction[1]
                    dist = 1
                    if(arrow == direction[2]): dist = 0
                    self.addNeighbours(adjList, m, n, r, c, newR, newC, dist)

        print(adjList)

        # Now our task is to reach from 0 to m*n-1 using 0-1 BFS.
        
        src = 0
        dst = m*n-1

        if(src == dst): return 0

        bfsQ = deque([src])

        # visited = [False]*(m*n)
        # visited[0] = True

        distance = [10**9]*(m*n)
        distance[0] = 0
        ans = 0

        while(len(bfsQ) > 0):
            qSize = len(bfsQ)
            # print("length is " + str(qSize))
            while(qSize > 0):
                frontNode = bfsQ.popleft()
                neighbours = adjList[frontNode]

                # print("node is " + str(frontNode))

                for neighbour in neighbours:
                    node = neighbour[0]
                    w = neighbour[1]

                    # if(visited[node] == True): continue

                    # visited[node] = True
                    # if(visited[dst] == True): return ans

                    if(distance[node] <= w + distance[frontNode]): continue

                    distance[node] = w + distance[frontNode]

                    if(w == 0):
                        # So, we need to add it at front.
                        bfsQ.appendleft(node)
                        # It will increase the current level size too
                        qSize = qSize + 1
                    else:
                        # So, distance is 1.
                        bfsQ.append(node)
                
                qSize = qSize - 1

            print("level change")

            # ans = ans + 1

        return distance[dst]