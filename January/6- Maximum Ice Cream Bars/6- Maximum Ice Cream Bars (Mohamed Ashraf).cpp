//Author: Mohamed Ashraf

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int conuter = 0;
        sort(costs.begin() , costs.end());
        for(auto cost : costs){
            if(coins >= cost) conuter++ , coins -= cost;
        }
        // Return the total number of Ice Cream Bars purchased
        return conuter;
    }
};