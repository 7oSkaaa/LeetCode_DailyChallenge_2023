// Author: Ahmed Hossam

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sorting the costs to iterate on them in ascending order
        sort(costs.begin(), costs.end());

        // number of ice_creams that will be bought
        int ice_creams = 0;

        for(auto& cost : costs){
            // if my coins can buy this ice_cream so let's by it.
            if(coins >= cost)
                coins -= cost, ice_creams++;
        }

        // the maximum number of ice cream bars
        return ice_creams;
    }
};
