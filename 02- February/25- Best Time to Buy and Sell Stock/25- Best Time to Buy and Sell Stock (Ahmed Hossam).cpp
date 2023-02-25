// Author: Ahmed Hossam

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // make vector prices in increasing order to get the max price after current
        vector < int > sorted(prices.size());
        sorted.back() = prices.back();
        for(int i = prices.size() - 2; i >= 0; i--)
            sorted[i] = max(sorted[i + 1], prices[i]);

        // the best profit will be max value after current - current
        int Max = INT_MIN;
        for(int i = 0; i < prices.size(); i++)
            Max = max(Max, sorted[i] - prices[i]);
        return Max;
    }
};
