//Author: Walaa AbdElhady

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //two pointers to search about answer
        // L is Buy and R is Sell 
        int n = prices.size(), l = 0, r = 0, ans = 0;
        while (r < n) {
            // if the current price (sell) is greater than the Buy price
            if (prices[r] > prices[l]) {
                // find the max profit
                ans = max(ans, prices[r] - prices[l]);
                // increase the the right pointer to find if there is another buyPrice grater than sellPrice
                r++;
            }
            else {
                // save the sellPrice as buyPrice and 
                // increase the the right pointer to find if there is another buyPrice grater than sellPrice
                l = r;
                r++;
            }
        }
        // return max profit can get
        return ans;
    }
};