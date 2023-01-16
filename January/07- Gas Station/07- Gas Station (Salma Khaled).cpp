// Author : Salma Khaled
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       //see if we have a solution
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
        }
       // return 0 if we don't have
        if (total < 0) {
            return -1;
        }
   
        // find out where to start
        int tank = 0;
        int start = 0;
        for (int i = 0; i < gas.size();i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return start; 
    }
};
