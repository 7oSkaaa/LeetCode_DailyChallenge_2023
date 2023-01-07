// Author : Mazen Alasas
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Tfuel = 0, Tcost = 0, sol = 0, tank = 0;            
        for (int i = 0; i < gas.size();i++) {
            Tfuel += gas[i];   // calc total fuel
            Tcost += cost[i];   // calc total cost
            tank += gas[i] - cost[i];   // current fuel
            if (tank < 0) {    // If current fuel is -ve that means we can't come to the next station
                sol = i + 1;    
                tank = 0;
            }
        }
        // If the total cost is enough return sol Otherwise -1
        return Tfuel < Tcost ? -1 : sol;
    }
};
