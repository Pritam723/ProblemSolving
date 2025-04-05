class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        start = 0

        fuel = 0
        deficit = 0
        # balance = 0

        i = 0
        while(i < n):
            fuel = fuel + gas[i] - cost[i]

            if(fuel < 0):
                # It means say we are starting from Station A
                # and we have reached A->B->C and we are failing at
                # Sattion D, surely It means starting from A is not fine.
                # And since A->B is +ve too. Surely We can't start from
                # B or C either. (Think about it). So, check from D now.
                deficit = deficit + abs(fuel)
                fuel = 0
                start = (i + 1)%n
            
            i = i + 1

        # So, once we reach n. We have to check current fuel with deficit.
        if(fuel >= deficit): return start
        return -1