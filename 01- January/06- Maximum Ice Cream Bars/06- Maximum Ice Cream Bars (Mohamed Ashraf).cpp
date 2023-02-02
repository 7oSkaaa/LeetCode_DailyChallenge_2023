//Author: Mohamed Ashraf

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int conuter = 0;
        // Sort costs to pick the min values
        sort(costs.begin() , costs.end());
        for(auto cost : costs){
            // if my coins enough to buy, do it.
            if(coins >= cost) conuter++ , coins -= cost;
        }
        // Return the total number of Ice Cream Bars purchased
        return conuter;
    }
};
