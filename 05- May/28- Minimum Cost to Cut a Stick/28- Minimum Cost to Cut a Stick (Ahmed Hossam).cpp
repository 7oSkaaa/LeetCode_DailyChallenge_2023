// Author: Ahmed Hossam

class Solution {
public:

    int minCost(int n, vector < int >& cuts) {
        // Get the size of the cuts vector
        int m = cuts.size();

        // Insert 0 at the beginning and n at the end of the cuts vector
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        
        // Sort the cuts vector in ascending order
        sort(cuts.begin(), cuts.end());
        
        // Create a 2D vector dp to store the minimum cost values
        vector < vector < int > > dp(m + 5, vector < int > (m + 5, INT_MAX));
        
        // Initialize the base case where l > r with 0 cost
        for(int l = 0; l <= m + 1; l++)
            for(int r = l - 1; r >= 0; r--)
                dp[l][r] = 0;
        
        // Calculate the minimum cost for each subproblem
        for(int l = m; l >= 1; l--)
            for(int r = 1; r <= m; r++)
                for(int idx = l; idx <= r; idx++)
                    // Update the minimum cost based on the cuts and subproblems
                    dp[l][r] = min(dp[l][r], cuts[r + 1] - cuts[l - 1] + dp[l][idx - 1] + dp[idx + 1][r]);
        
        // Return the minimum cost of the original problem
        return dp[1][m];
    }
};
