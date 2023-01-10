# Author: Lobna Mazhar

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Loop on the gas and cost, assume current index is the start_index if no start_index was detected yet
        # Calculate accumulative total gas
        # Calculate current gas amount, if the current amount goes below 0, re-init current to 0 and start_index to -1
        total_gas, current, start_index = 0, 0, -1
        for i in range(len(gas)):
            if start_index == -1: start_index = i
            total_gas += gas[i] - cost[i]
            current += gas[i] - cost[i]
            if current < 0: current, start_index = 0, -1
        # return the start_index if the total gas is more than 0 so it's enough for the whole round
        return start_index if total_gas >= 0 else -1