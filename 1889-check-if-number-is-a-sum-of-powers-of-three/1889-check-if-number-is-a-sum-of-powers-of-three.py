def maxPower(n):
    start = 1
    power = 0
    
    while(n > start):
        start = start * 3
        power = power + 1
    return power
    

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        exp = maxPower(n)
        # print(exp)
        start = 3**exp
        
        target = n
        
        while(target > 0):
            # print(target, start)
            if(target > start * 3): return False

            # So, start is >= target.
            if(target - start < 0):
                start = start//3
                continue

            target = target - start
            start = start//3
            
            
        if(target == 0): return True
        return False