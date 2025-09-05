class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        # No moves needed to make num1 zero.
        if num1 == 0:
            return 0

        # Find num_ops such that this equation is satisfied.
        # num1 = num_ops * num2 + (sum of |num_ops| powers of 2)
        num_ops = 0
        while True:
            num_ops += 1

            # Check if |remaining| can be generated using
            # |num_ops| powers of 2.
            remaining = num1 - num2 * num_ops
            
            # No point in continuing the search if 
            # num2 * num_ops > num1. We only have access to
            # positive powers of 2.
            if remaining < 0:
                return -1
            
            # Count the number of '1's in the binary representation
            # of |remaining|. This is the minimum number of powers of
            # 2 needed to generate the number.
            def num_of_ones_binary(num):
                num_ones = 0
                while num != 0:
                    num_ones += (num & 1)
                    num = num // 2
                return num_ones

            num_ones_binary = num_of_ones_binary(remaining)
            
            # num_ops must be within [num_ones_binary, remaining].
            # At minimum, we need |num_ones_binary| to generate the 
            # number. At maximum, we can use |remaining| numbers,
            # where each power of a 2 is a 1.
            if num_ops >= num_ones_binary and num_ops <= remaining:
                return num_ops

        return num_ops