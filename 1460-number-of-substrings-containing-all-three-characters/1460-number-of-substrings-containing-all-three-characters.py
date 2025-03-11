class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        charCount = [0]*3
        uniqueChars = 0

        n = len(s)

        l, r = 0, 0

        ans = 0

        while(r < n):
            ch = s[r]
            chIdx = ord(ch) - ord('a')
            charCount[chIdx] += 1

            if(charCount[chIdx] == 1): uniqueChars += 1

            if(uniqueChars == 3):
                # print(l, r)
                # ans = ans + (n-r) Should not be here.
                # Take the example aaacb to see why. Because If we
                # Put here we miss aacb and acb

                # Also move the left pointer till uniqueChars become < 3 again.
                ptr = l
                while(uniqueChars == 3):
                    print(ptr, uniqueChars)
                    ans = ans + (n-r) # Should be here. Use example aaacb.

                    ch = s[ptr]
                    chIdx = ord(ch) - ord('a')
                    charCount[chIdx] -= 1

                    if(charCount[chIdx] == 0): uniqueChars -= 1

                    ptr += 1
                
                l = ptr

            r = r + 1


        # print(ord('a') - ord('a'))

        return ans