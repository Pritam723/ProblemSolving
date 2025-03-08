class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        
        # Basically we need no. of whites in every k sized window.
        # We want the minimum of it.
        
        white_seen = 0
        black_seen = 0

        n = len(blocks)

        i = 0


        while(i < k):
            ch = blocks[i]

            if(ch == 'W'):
                white_seen += 1


            i = i + 1

        minOp = white_seen

        while(i < n):
            ch_add = blocks[i]
            ch_remove = blocks[i - k]

            if(ch_add == 'W'):
                white_seen += 1
            if(ch_remove == 'W'):
                white_seen -= 1
            
            minOp = min(minOp, white_seen)
            i = i + 1

        return minOp
