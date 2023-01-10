// Author: Mahmoud Aboelsoud

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort the costs of the ice cream bars
        sort(costs.begin(), costs.end());
        
        int ans = 0;
        for(auto&i: costs){
            // if you can't buy the current ice cream bar that means you can't buy anyone of the remaining so we end our loop
            if(i > coins) break;
            
            // buy the current ice cream bar remove it's value from the total money you have and increase the ans by 1
            coins -= i, ans++;
        }

        return ans;
    }
};
