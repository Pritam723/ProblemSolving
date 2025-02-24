def dfs(parent, i, n, bob, adjList, path1, path2, currentPath):
    currentPath.append(i)

    if(i == n-1): path1.extend(currentPath.copy())
    if(i == bob): path2.extend(currentPath.copy())


    neighbours = adjList[i]

    for neighbour in neighbours:
        if(neighbour == parent): continue
        dfs(i, neighbour, n, bob, adjList, path1, path2, currentPath)
    
    currentPath.pop()
    return


def dfs2(parent,i,n,adjList,point,maxPoint,timeMapBob,t,amount):
    # We are here means at time = t we are at i.

    bobTiming = timeMapBob[i]

    gain = 0
    if(bobTiming < t):
        # alice gets no point.
        gain = 0
    elif(bobTiming == t):
        gain = amount[i]//2
    else:
        gain = amount[i]

    point = point + gain
    print(i,t,bobTiming, gain)


    # Now we visit neighbour, but first check if we are at leaf.
    neighbours = adjList[i]
    if(i != 0 and len(neighbours) == 1):
        maxPoint[0] = max(maxPoint[0], point)
        return
    
    for neighbour in neighbours:
        if(neighbour == parent): continue

        dfs2(i,neighbour,n,adjList,point,maxPoint,timeMapBob,t+1,amount)
    

    point = point - gain
    return



class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        # First using DFS figure out the only path from 0 to bob
        # and from 0 to n-1.

        n = len(edges) + 1

        path1 = []
        path2 = []
        currentPath = []

        adjList = {}

        for i in range(n):
            adjList[i] = []

        for edge in edges:
            src = edge[0]
            dest = edge[1]

            adjList[src].append(dest)
            adjList[dest].append(src)
        
        parent = -1 # Only use this, no need of visited array.
        i = 0
        dfs(parent, i, n, bob, adjList, path1, path2, currentPath)

        path2.reverse()
        # print(path1)
        # print(path2)

        ################################################################################
        # But actually we got the Last Part wrong.
        # Alice is not reaching n-1 always. She is reaching any of the leafs. So, till now
        # we got the bob path which is 3->1->0 in this case. [3,1,0] means that at time = 0
        # bob is at 3, at time = 2, bob is at 0. So, why not keep a map of when bob reaches what.
        timeMapBob = {}
        for i in range(n):
            timeMapBob[i] = n

        for idx, item in enumerate(path2):
            timeMapBob[item] = idx

        print(timeMapBob) # n means bob never reaches it.

        maxPoint = [-10**10]
        point = 0
        parent = -1
        i = 0
        t = 0

        dfs2(parent,i,n,adjList,point,maxPoint,timeMapBob,t,amount)

        return maxPoint[0]