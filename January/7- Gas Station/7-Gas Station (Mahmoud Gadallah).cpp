/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /** Approach
         * on each station we calcluate "state" which is gas - cost so it will indicate if we `need gas` (state < 0) or `feed gas` (state > 0)
         * tank --> indicate summation of all states if tank state is `need` then we return -1
         * tot --> also accumulating states untill tot state become `need` so choosen indx isn't right we will move it to i + 1
        */
        int n = gas.size();
        int tot = 0, tank = 0, idx = 0;     


        for (int i = 0; i < n; ++i){
            int state = gas[i] - cost[i];
            tank += state;
            tot += state;

            if (tot < 0)
                tot = 0, idx = i + 1;
        }
        if (tank < 0)
            return -1;
        
        return idx;
    }
};