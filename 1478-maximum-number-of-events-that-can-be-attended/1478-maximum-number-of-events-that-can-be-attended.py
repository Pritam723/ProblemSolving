class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        INF = 10 ** 20
        evt = collections.defaultdict(list)

        for s, e in events:
            evt[s].append(e)
        
        count = 0
        lt = INF
        h = []
        for t in sorted(evt.keys()):
            while len(h) > 0 and lt < t:
                e = heapq.heappop(h)
                if e >= lt:
                    count += 1
                    lt += 1
                else:
                    pass
            lt = t

            for e in evt[t]:
                heapq.heappush(h, e)
        t = INF

        while len(h) > 0 and lt < t:
            e = heapq.heappop(h)
            if e >= lt:
                count += 1
                lt += 1
        return count