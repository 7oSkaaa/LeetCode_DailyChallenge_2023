// Author: Ahmed Gamal

// this is the iterative solution for the problem with the same idea of the recursive solution
// for more details about the problem, and solution idea, please check the recursive solution implemented in javascript

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // n piles, k coins
        const int n = int(piles.size());

        // dp[i][j] = maximum value of j coins from the first i piles
        // dp: the previous row
        vector<int> dp(k + 1);


        // for each pile
        for(int i = 0; i < n; i++) {
            // dp_: the current row
            vector<int> dp_(k + 1);

            // for each number of coins remaining
            for(int j = 0; j <= k; j++) {
                // the answer for the current row is the same as the previous row (initially)
                dp_[j] = dp[j];

                // for each number of coins we can take from the current pile
                int sum = 0;
                for(int p = 0; p <= j; p++) {
                    // if we reached the end of the current pile, break
                    if(p > piles[i].size()) {
                        break;
                    }
                    // if we can take p coins from the current pile, and we can take j - p coins from the previous piles
                    dp_[j] = max(dp_[j], dp[j - p] + sum);

                    // add the next coin from the current pile
                    if(p < piles[i].size())
                        sum += piles[i][p];
                }
            }

            // swap the current row with the previous row
            swap(dp, dp_);
        }

        // the answer is the maximum value of k coins from the first n piles
        return dp[k];
    }
};