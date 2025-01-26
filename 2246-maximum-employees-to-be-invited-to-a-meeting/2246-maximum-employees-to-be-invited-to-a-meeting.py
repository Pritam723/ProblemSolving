class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        
        # if a likes b, construct an edge reversely (b -> a) to make following BFS easier
        invG = defaultdict(list)
        for idx, fav in enumerate(favorite):
            invG[fav].append(idx)
        
        # function for finding the extended path of 2-cycle
        def bfs(start, seen):
            q = deque([(start, 0)])
            ans = 0 
            while q:
                pos, dist = q.popleft()
                for neib in invG[pos]:
                    if neib in seen:
                        continue
                    seen.add(neib)
                    q.append((neib, dist+1))
                    ans = max(ans, dist + 1)
            return ans
        
        
        N = len(favorite)
        
        # solution derived from a single large cycle & all 2-cycles
        ans_large_cycle, ans_2_cycles = 0, 0 
        
        # finding all cycles
        for i in range(N): 
            if favorite[i] != -1:  # not explored before, do a DFS here
                dist = {i: 0}  # record the order of exploration
                while favorite[i] != -1:
                    nxt = favorite[i]
                    favorite[i] = -1
                    if nxt in dist:  # detect cycle
                        cycle_len = len(dist) - dist[nxt]  # the real cycle length
                        
                        # update the solution derived from a single large cycle
                        ans_large_cycle = max(ans_large_cycle, cycle_len) 
                        
                        # update the solution derived from 2-cycle and its extended path
                        if cycle_len == 2: 
                            # i is the currrent vertex and nxt is the next vertex
                            ans_2_cycles += 2 + bfs(nxt, {i, nxt}) + bfs(i, {i, nxt}) 
                    else:
                        i = nxt
                        dist[nxt] = len(dist)

        return max(ans_large_cycle, ans_2_cycles)