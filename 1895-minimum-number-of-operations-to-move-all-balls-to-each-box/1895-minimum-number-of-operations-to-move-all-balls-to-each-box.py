class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        
        ans = [0]*n

        for i in range(n):
            moves = 0
            for j in range(n):
                if(boxes[j] == '0' or i == j): continue
                moves = moves + abs(j-i)
            ans[i] = moves

        return ans