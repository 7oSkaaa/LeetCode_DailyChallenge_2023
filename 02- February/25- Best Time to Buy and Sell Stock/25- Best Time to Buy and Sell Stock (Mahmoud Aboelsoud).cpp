// Author: Mahmoud Aboelsoud

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // you can't sell before buying so you have to buy first then sell 
        // so you have to find the minimum price before the maximum price 
        // so we will iterate over the array and keep the minimum price
        // and the maximum profit we can get

        // make the minimum price the first day price, and the maximum profit 0
        int mn = prices[0], ans = 0;
        // iterate over the array
        for(auto&i: prices){
            // find the minimum price
            mn = min(mn, i);
            // find the maximum profit
            ans = max(ans, i - mn);
        }
        // return the maximum profit
        return ans;
    }
};
