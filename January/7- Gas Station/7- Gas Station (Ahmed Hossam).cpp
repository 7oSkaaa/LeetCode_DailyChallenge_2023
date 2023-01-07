// Author: Ahmed Hossam

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // check if impossible to get solution
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        if(total_gas < total_cost)
            return -1;
        
        int curr_gas = 0, starting_point = 0;
        for(int i = 0; i < n; i++){
            
            // update current amount of gas with the status of the station[i]
            curr_gas += gas[i] - cost[i];

            // update the start point if the last one is invalid
            if(curr_gas < 0)
                curr_gas = 0, starting_point = i + 1;
        }

        return starting_point;
    }
};
