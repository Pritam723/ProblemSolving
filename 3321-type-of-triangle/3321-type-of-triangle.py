class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = nums[0], nums[1], nums[2]
        
        if(not (a+b > c and a+c > b and b+c > a)):
            return "none"

        if(a == b and b == c):
            return "equilateral"
        
        if(a == b or b == c or a == c):
            return "isosceles"

        return "scalene"