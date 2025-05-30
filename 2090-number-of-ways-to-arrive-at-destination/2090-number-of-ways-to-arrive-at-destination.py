from heapq import *
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # create adjacency list
        adj_list = defaultdict(list)
        for i,j,k in roads:
            adj_list[i].append((j,k))
            adj_list[j].append((i,k))
            
        start = 0
        end = n-1
        
        # set minimum distance of all nodes but start to infinity.
        # min_dist[i] = [minimum time from start, number of ways to get to node i in min time]
        min_dist = {i:[float('inf'),0] for i in adj_list.keys()}
        min_dist[start] = [0,1]
             
        # Heap nodes in the format (elapsed time to get to that node, node index)
        # This is done so as to allow the heap to pop node with lowest time first
        # Push first node to heap.
        heap = [(0, start)]
        while heap:
            elapsed_time, node = heappop(heap)
            # if nodes getting popped have a higher elapsed time than minimum time required
            # to reach end node, means we have exhausted all possibilities
            # Note: we can do this only because time elapsed cannot be negetive
            if elapsed_time > min_dist[end][0]:
                break
            for neighbor, time in adj_list[node]:
                # check most expected condition first. Reduce check time for if statement
                if (elapsed_time + time) > min_dist[neighbor][0]:
                    continue
                # if time is equal to minimum time to node, add the ways to get to node to
                # the next node in minimum time
                elif (elapsed_time + time) == min_dist[neighbor][0]:
                    min_dist[neighbor][1] += min_dist[node][1]
                else: # node has not been visited before. Set minimum time 
                    min_dist[neighbor][0] = elapsed_time + time
                    min_dist[neighbor][1] = min_dist[node][1]
                    heappush(heap, (elapsed_time+time,neighbor))

        return min_dist[end][1]%(pow(10,9)+7)
        