class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        m, n = len(moveTime) - 1, len(moveTime[0]) - 1
        heap = [(0, 0, 0, True)]
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        visited = set()
        while heap:
            time, r, c, check = heapq.heappop(heap)
            if (r, c) == (m, n): return time
            new = 1 if check else 2
            for x, y in directions:
                row, col = x + r, y + c
                if row <= m and col <= n and col >= 0 and row >= 0 and (row, col) not in visited:
                    heapq.heappush(heap, (max(time, moveTime[row][col]) + new, row, col, not check))
                    visited.add((row, col))