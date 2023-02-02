// Author: Anwar Rizk

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        // If the total cost is greater than the total gas, then it is impossible to complete the circuit
        // So we return -1
        totalGas = accumulate(gas.begin(), gas.end(), 0);
        totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalCost > totalGas) return -1;
        // If the total cost is less than the total gas, then we can complete the circuit
        // So we return the index of the starting point
        int currGas = 0, startIdx = 0;
        for(int i = 0; i < n; i++){
            // If the current gas is less than 0, then we reset the current gas to 0 and the starting index to the next index
            currGas += gas[i] - cost[i];
            if(currGas < 0) currGas = 0, startIdx = i + 1;
        }
        return startIdx;
    }
};