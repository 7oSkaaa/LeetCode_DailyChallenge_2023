// Author: Eileanora

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int curr_gas = 0 , total_gas = 0 , ans = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            total_gas += (gas[i] - cost[i]);  //calculate total gas and costs for all stations
            curr_gas += (gas[i] - cost[i]);   //current gas circulating from index ans
            if(curr_gas < 0)  
            {
                /*
                - if it goes below zero then it's not valid and all index before it are not valid
                   as it will still lead to a ngeative sum
                we reset the sum and starting index
                */
                curr_gas = 0;
                ans = i + 1;
            }
        }
        if(total_gas < 0) //if total gas goes below zero then there is not valid solution
            return -1;
        return ans; 
    }
};
