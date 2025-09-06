class Solution:
    def minOperations(self, queries: list[list[int]]) -> int:
        
        memo_F = {}

        def calculate_F(N: int) -> int:
            if N in memo_F:
                return memo_F[N]
            if N == 0:
                return 0
            
            total_sum = 0
            power_of_4 = 1
            k = 1
            
            while True:
                next_power_of_4 = power_of_4 * 4
                if next_power_of_4 > N:
                    break
                
                count = 3 * power_of_4
                total_sum += count * k
                
                power_of_4 = next_power_of_4
                k += 1
            
            remaining_count = N - power_of_4 + 1
            total_sum += remaining_count * k
            
            memo_F[N] = total_sum
            return total_sum

        total_operations = 0
        for l, r in queries:
            sum_ops_r = calculate_F(r)
            sum_ops_l_minus_1 = calculate_F(l - 1)            
            ops_for_query = sum_ops_r - sum_ops_l_minus_1            
            min_ops_for_query = (ops_for_query + 1) // 2            
            total_operations += min_ops_for_query
            
        return total_operations