from collections import deque
from itertools import permutations
from math import inf

class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        idx = [[] for _ in range(5)]  # store indices for digits 0 to 4
        for i, c in enumerate(s):
            idx[int(c)].append(i)

        idx = [q for q in idx if q]  # filter out digits that didn't appear
        n = len(s)
        for q in idx:
            q.append(n)  # sentinel to simplify logic

        def sol(q1, q2):
            que = [deque() for _ in range(4)]  # 4 deques for different parities
            prev = [inf] * 4  # min values for each parity state
            que[0].append((max(q1[0], q2[0], k-1), 0))
            i = j = 0
            best = -inf
            curr = -1

            while q1[i] != q2[j]:  # until we reach the end
                if q1[i] < q2[j]:
                    curr = max(curr, q1[i])
                    i += 1
                else:
                    curr = max(curr, q2[j])
                    j += 1

                right = min(q1[i], q2[j]) - 1
                parity = (i & 1) | ((j & 1) << 1)
                prev_p = parity ^ 1

                while que[prev_p] and que[prev_p][0][0] <= right:
                    _, prev[prev_p] = que[prev_p].popleft()

                best = max(best, i - j - prev[prev_p])
                v = i - j

                if v < prev[parity] and (not que[parity] or v < que[parity][-1][1]):
                    que[parity].append((max(curr + k, q1[i], q2[j]), v))

            return best

        ans = -inf
        for q1, q2 in permutations(idx, 2):
            ans = max(ans, sol(q1, q2))

        return ans