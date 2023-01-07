// Author: Noura Algohary
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Depending on the assumption that there is only one solution. "If there exists a solution, it is guaranteed to be unique" 
        int tank = 0,full_tank=0, total_cost=0,start_station = 0;

        for(int i=0;i<gas.size();i++)
        {
            full_tank += gas[i];
            total_cost += cost[i];
        }
        // Return -1 if there is no solution, when the total gas(full_tank) is less then the cost to travel through all stations(total_cost)
        if(full_tank < total_cost)
            return -1;

        for(int i=0;i<gas.size();i++)
        {
            tank += gas[i] - cost[i];


            // The cost is more than the gas tank(tank < 0), then this station must be the last one, and the next station is the start
            if(tank < 0)
            {
                 start_station = i + 1;
                 tank = 0;
            }
        }

        return start_station;
    }
};