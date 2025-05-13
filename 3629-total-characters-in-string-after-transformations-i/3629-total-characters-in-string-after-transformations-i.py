class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:

        M = 10**9 + 7
        
        curr_map = [0]*26
        empty_map = [0]*26

        # for i in range(26):
        #     ch = chr(ord('a') + i)
        #     curr_map[ch] = 0
        #     empty_map[ch] = 0


        for ch in s:
            chOrd = ord(ch) - ord('a')
            curr_map[chOrd] += 1

        it = 0
        while(it < t):
            # print(curr_map)
            # Initialize it everytime.
            increment = empty_map.copy()
            
            for i in range(26):

                # key = chr(ord('a') + i)
                
                if(i == 25):
                    increment[0] += curr_map[i]
                    increment[1] += curr_map[i]
                else:
                    # nextKey = chr(ord(key) + 1)
                    increment[i+1] += curr_map[i]
                curr_map[i] = 0

            # Apply this on the curr_map.
            # print(increment)
            for i in range(26):
                curr_map[i] = curr_map[i] + increment[i]

            it = it + 1
        
        L = 0
        for i in range(26):
            L = (L + curr_map[i]) % M

        return L