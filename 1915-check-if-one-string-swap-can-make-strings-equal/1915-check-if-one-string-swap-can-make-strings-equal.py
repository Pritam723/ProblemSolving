class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        differ = 0
        n = len(s1)

        s1_mismatch = ""
        s2_mismatch = ""
      

        for i in range(n):
            if(s1[i] != s2[i]):
                s1_mismatch = s1_mismatch + s1[i]
                s2_mismatch = s2[i] + s2_mismatch
                differ = differ + 1
            
            if(differ > 2): break

        if(differ == 0): return True
        if(differ != 2): return False

        return (s1_mismatch == s2_mismatch)

