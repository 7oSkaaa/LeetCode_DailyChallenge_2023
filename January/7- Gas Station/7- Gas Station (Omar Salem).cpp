//Author: Omar Salem
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0 , total_cost = 0 , cur_gas = 0 , ans = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            total_gas += gas[i] ;
            total_cost +=cost[i];

            cur_gas += gas[i] - cost[i]; 
            if(cur_gas < 0 ) // current gas is not enough go to next station 
                ans = i + 1 , cur_gas = 0;
        }
        // If the total gas is less than the total cost, it is impossible to find a station 
        return (total_gas < total_cost ? -1 : ans);
    }
};