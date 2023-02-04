//Author: Omar Salem
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        /*
        sort costs 
        if cost of ice cream bar <= coins then you can buy it
        and deduct its price from coins
        */
        int ans = 0;
        for(auto &i : costs)
            if(coins >= i)
                ans ++ , coins -= i;
        return ans;
    }
};