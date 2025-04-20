def bin_search(answers, s, e, val):
    idx = s # because we are sure that answers[s] == val

    while(s <= e):
        m = s + (e-s)//2

        if(answers[m] == val):
            idx = m # Potential idx
            s = m + 1 # Try to search at right
        elif(answers[m] < val):
            s = m + 1
        else:
            e = m - 1

    return idx

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        # See [10,10,10], With the first 10 we can
        # cover 11 number of other 10s for sure. And
        # a 10 will contribute to 11 if we think about it.
        # Same way, [1,1,2] -> 1 will contribute to 2 and we
        # can at max cover run of 2 no. of 1s with it.
        # Again for arr[2] = 2, max run of 2 we can take is 3
        # and it will together contribute to 3. And to find how
        # many number of such run of x is there, we can use binary
        # search too.

        n = len(answers)
        answers.sort()

        i = 0
        minRabbit = 0

        while(i < n):
            val = answers[i]
            # So, with val, it will contribute to val+1
            # And we can take run of val+1 no. of ans with it.
            s = i
            e = min(i + val, n-1)
            # Because at max we can cover from index s to index e.
            # Now, check where is the last "val" in this range.
            idx = bin_search(answers, s, e, val)
            # So, we need to see the length of the run.
            # lengthOfRun = idx - s + 1
            minRabbit = minRabbit + val + 1
            i = idx + 1

        return minRabbit