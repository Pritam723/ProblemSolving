class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        consecutiveOdds = 0

        for num in arr:
            if(num % 2 == 1):
                consecutiveOdds += 1
            else:
                consecutiveOdds = 0

            if(consecutiveOdds == 3):
                return True
            
        return False