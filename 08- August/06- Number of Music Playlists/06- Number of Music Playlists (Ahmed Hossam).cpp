// Author: Ahmed Hossam

class Solution {
public:
    // Define a constant variable MOD to be used in modulo operations
    const int MOD = 1e9 + 7;

    // Helper function to perform multiplication with modulo
    int mul(int res, int to_mul) {
        // Return the result of multiplying res and to_mul, and taking the modulo of MOD
        return res = (1ll * (res % MOD) * (to_mul % MOD)) % MOD;
    }

    int solve(int n, int goal, int k, vector<vector<int>>& dp) {
        // Base case: If both n and goal are 0, return 1 as one valid playlist is found
        if (n == 0 && goal == 0) return 1;

        // Base case: If either n or goal is 0, return 0 as no valid playlist can be formed
        if (n == 0 || goal == 0) return 0;
        
        // reference for dp[n][goal]
        int& ret = dp[n][goal];

        // If the result for the current state (n, goal) is already computed, return it from the dp table
        if (~ret) return ret;

        // Calculate the number of ways to pick a song and place it at the end of the playlist
        int pick = mul(solve(n - 1, goal - 1, k, dp), n);

        // Calculate the number of ways to place a new song (not already in the playlist) at the end
        // This can be done by choosing from the songs not played in the last k steps
        int notpick = mul(solve(n, goal - 1, k, dp), max(n - k, 0));

        // Store the result in the dp table and return it after taking the modulo of MOD
        return ret = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        // Create a dp table to store the results of subproblems
        vector < vector < int > > dp(n + 1, vector < int > (goal + 1, -1));

        // Call the solve function to compute the result and return it
        return solve(n, goal, k, dp);
    }
};
