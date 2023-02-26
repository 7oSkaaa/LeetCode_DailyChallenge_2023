//Author: Sara Hamza

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            approach: simulate the problem
            ans = maximum(which comes after this minimum) - minimum

            to get maximum correctly: while updating the minimum => reset the maximum to a small value

        */
        int n = prices.size();
        int mn = 1e9, mx = -1e9, ans = 0;
        for(int i = 0; i < n; ++i){

            if(mn > prices[i]){
                mn = prices[i];
                mx = -1e9; // reset mx
            }

            mx = max(mx, prices[i]);

            ans = max(ans, mx - mn);
        }
        return ans;
    }
};
