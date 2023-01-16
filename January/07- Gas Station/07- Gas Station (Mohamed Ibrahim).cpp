//Author: Mohamed Ibrahim

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
    // Add the gas at the current station and subtract the cost to travel to the next station
            tank += gas[i] - cost[i];
    // Add the same value to the total
            total += gas[i] - cost[i];
    // If the tank is negative, this means we cannot reach the next station
    // Set the start index to the next station and reset the tank
            if (tank<0) {
                start = i + 1;
                tank = 0;
        }
    }
// If the total is greater than or equal to 0, this means we can reach all stations
// Return the start index
// Otherwise, return -1 as it is not possible to complete the circuit
        return (total>=0) ? start : -1;
    }
};
