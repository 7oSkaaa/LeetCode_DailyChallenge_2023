// Author: Mina Magdy

// Define a class Solution
class Solution {
public:
    vector<vector<vector<int>>> dp; // Dynamic programming memoization table
    
    // Constructor to initialize the dp table
    Solution() {
        dp.assign(100, vector<vector<int>>(100, vector<int>(2, -1)));
    }
    
    // Recursive function to play the stone game
    int rec(vector<int>& piles, int idx = 0, int M = 1, int turn = 1) {
        // Base case: if all piles have been visited, return 0
        if (idx >= piles.size())
            return 0;

        // Check if the current state has already been calculated
        int &ret = dp[idx][M][turn];
        if (~ret)
            return ret;

        // Turn 1: Alex's turn
        if (turn) {
            ret = 0;
            int sum = 0;
            for (int X = 1; idx + X - 1 < piles.size() && X <= 2 * M; X++) {
                sum += piles[idx + X - 1];
                ret = max(ret, sum + rec(piles, idx + X, max(M, X), !turn));
            }
        }
        // Turn 0: Lee's turn
        else {
            ret = 1e9;
            for (int X = 1; idx + X - 1 < piles.size() && X <= 2 * M; X++) {
                ret = min(ret, rec(piles, idx + X, max(M, X), !turn));
            }
        }
        return ret;
    }
    
    // Function to calculate the maximum number of stones Alex can get
    int stoneGameII(vector<int>& piles) {
        return rec(piles);
    }
};
