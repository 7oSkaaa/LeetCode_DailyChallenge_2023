// Author: Eileanora

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int ans = 0; 
        for(int i = 0; i < costs.size(); i++)
        {
            coins -= costs[i];  //buy the ith icecream
            if(coins >= 0)  // if money not below zero but it
                ans++;
            else
                break;  //if current money goes below zero then he cant buy anymore
        }
        return ans;
    }
};
