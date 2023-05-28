// Author: Ahmed Hossam

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][m] represents the maximum number of stones the player can obtain
        // when starting at pile i with a maximum pick of m.
        vector < vector < int > > dp(n, vector < int > (2 * n + 5));
        
        // sum[i] stores the sum of stones from pile i to the end.
        vector < int > sum(n + 5);
        
        // Calculate the sum of stones from each pile to the end.
        for (int i = n - 1; i >= 0; i--)
            sum[i] = piles[i] + sum[i + 1];
        
        // Iterate over the piles from right to left.
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over the maximum pick from 1 to n.
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n)
                    // If there are not enough piles remaining, take all the stones.
                    dp[i][m] = sum[i];
                else {
                    // Consider all possible picks from 1 to 2 * m.
                    for (int x = 1; x <= 2 * m; x++)
                        // Calculate the maximum stones the player can obtain
                        // by either taking x stones and recursively solving for the remaining piles,
                        // or not taking any stones and letting the other player play.
                        dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(m, x)]);
                }
            }
        }
        
        // The maximum number of stones the first player can obtain starting from the first pile
        // with a maximum pick of 1 is stored in dp[0][1].
        return dp[0][1];
    }
};
