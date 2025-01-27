from collections import deque

class Solution:
    
    def bfs(self, isReachable, i, adjList, numCourses):
        visited = [False]*numCourses

        bfsQ = deque([i])
        visited[i] = True
        isReachable[i][i] = True
        
        while(len(bfsQ) > 0):
            fn = bfsQ.popleft()

            for neighbour in adjList[fn]:
                if(visited[neighbour] == True): continue
                visited[neighbour] = True
                isReachable[i][neighbour] = True
                bfsQ.append(neighbour)


    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        isReachable = [[False]*numCourses for i in range(numCourses)]

        # print(isReachable)

        adjList = {}
        
        for i in range(numCourses):
            adjList[i] = []

        for prerequisite in prerequisites:
            a = prerequisite[0]
            b = prerequisite[1]

            adjList[a].append(b)

        
        for i in range(numCourses):
            self.bfs(isReachable, i, adjList, numCourses)

        print(isReachable)

        m = len(queries)
        ans = [False]*m

        for i in range(m):
            query = queries[i]
            u = query[0]
            v = query[1]

            if(isReachable[u][v]): ans[i] = True

        return ans