// Author: Ahmed Hossam

class Solution {
public:
    string stoneGameIII(const vector < int >& stones) {
        int n = stones.size();

        // Create a dynamic programming table with initial values set to -1e9
        vector < int > dp(n + 1, -1e9);

        // Set the value of the last cell in the dp table to 0
        dp[n] = 0;

        // Iterate backwards through the stones
        for (int i = n - 1; i >= 0; --i) {
            // Iterate from 0 to 2 (inclusive) to simulate taking 1, 2, or 3 stones
            for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
                // Calculate the total number of stones taken
                take += stones[i + k];

                // Update the value of dp[i] by taking the maximum of its current value
                // and the difference between the total number of stones taken and the value
                // of dp at the next position
                dp[i] = max(dp[i], take - dp[min(i + k + 1, n)]);
            }
        }

        // Create a vector with the possible outcomes: "Alice", "Tie", "Bob"
        vector < string > ans = {"Alice", "Tie", "Bob"};

        // Return the corresponding outcome based on the value of dp[0]
        return ans[(dp[0] == 0) + (dp[0] < 0) * 2];
    }
};
