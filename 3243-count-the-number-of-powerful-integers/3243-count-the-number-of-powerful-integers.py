class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        def solve(num):
            num_str = num
            num_len = len(num_str)
            suffix = str(s)
            suffix_len = len(suffix)

            if suffix_len>num_len:
                return 0

            prefix_len = num_len-suffix_len
            result=0

            for i in range(prefix_len):
                digit=int(num[i])

                # if digit is greater than limit
                if digit>limit:
                    result+=(limit+1)**(prefix_len-i)
                    return result
                else:
                    result+=digit*((limit+1)**(prefix_len-i-1))
            
            if num[-len(suffix):]>=suffix:
                result+=1
            
            return result
            

        
        return solve(str(finish))-solve(str(start-1))