class Solution:
    def dfs(self,graph, i, visited, isSafeNode):
        visited[i] = True

        isSafeFlag = True # Nodes having no outgoing edge will have True value.  
        for neighbour in graph[i]:
            if(neighbour == i): # Self-Loops.
                isSafeFlag = False
            if(visited[neighbour] == True):
                isSafeFlag = isSafeFlag and isSafeNode[neighbour]
            else:
                self.dfs(graph, neighbour, visited, isSafeNode)
                isSafeFlag = isSafeFlag and isSafeNode[neighbour]

        # Now, processing of all edge from this graph is done. So, we can
        # Assign the value now.
        isSafeNode[i] = isSafeFlag
        return

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        visited = [False]*n
        isSafeNode = [False]*n

        for i in range(n):
            if(visited[i] == True): continue
            self.dfs(graph, i, visited, isSafeNode)

        # print(isSafeNode)
        ans = []
        for i in range(n):
            if(isSafeNode[i] == True):
                ans.append(i)

        return ans