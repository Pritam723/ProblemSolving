class Solution:
    def maxBottlesDrunk(self, bottles: int, exchange: int) -> int:
        empty=bottles
        while empty>=exchange:
            bottles+=1
            empty=empty-exchange+1
            exchange+=1
        return bottles