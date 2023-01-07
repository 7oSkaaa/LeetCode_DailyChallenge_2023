# Author: Noura Algohary
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Depending on the assumption that there is only one solution. 
        # "If there exists a solution, it is guaranteed to be unique"
        tank = 0
        start_station = 0

        # Return -1 if there is no solution, when the total gas(full_tank) is less then the cost t
        if sum(gas) < sum(cost):
            return -1
        
        for i in range(len(gas)):
            tank += gas[i] - cost[i]

            # The cost is more than the gas tank(tank < 0), then this station must be the last one, and the next station is the start
            if tank < 0:
                start_station = i+1
                tank = 0
        
        return start_station
