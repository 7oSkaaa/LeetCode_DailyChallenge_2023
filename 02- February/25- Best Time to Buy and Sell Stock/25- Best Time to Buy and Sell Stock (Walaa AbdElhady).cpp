//Author: Walaa AbdElhady

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), l = 0, r = 0, ans = 0;
        while (r < n) {
            if (prices[r] > prices[l]) {
                ans = max(ans, prices[r] - prices[l]);
                r++;
            }
            else {
                l = r;
                r++;
            }
        }
        return ans;
    }
};