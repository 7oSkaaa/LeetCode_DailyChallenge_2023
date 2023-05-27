// Author: Mina Magdy

class Solution {
public:
    int n; // Number of stones
    vector<int> stoneValue; // Vector to store the values of the stones
    vector<vector<int>> dp; // 2D DP array for memoization
    
    // Function to calculate the maximum number of stones Alice can get
    int maxAliceStones(int idx = 0, int turn = 1) {
        // Base case: if the index is out of range, return 0
        if (idx >= n)
            return 0;

        // Check if the value is already calculated and stored in dp array
        if (dp[idx][turn] != -1e9)
            return dp[idx][turn];

        // Recursive cases
        if (turn) { // Alice's turn
            int sum = 0; // Variable to store the sum of stone values
            int mx = -1e9; // Variable to store the maximum number of stones Alice can get
            for (int i = 1; i <= 3; i++) {
                // Check if the current stone is within range
                if (idx + i - 1 < n)
                    sum += stoneValue[idx + i - 1];
                // Choose the maximum value between the current sum and the maximum number of stones Alice can get by choosing the next stone
                mx = max(mx, sum + maxAliceStones(idx + i, !turn));
            }
            // Store the calculated value in dp array and return it
            return dp[idx][turn] = mx;
        }
        else { // Bob's turn
            int mn = 1e9; // Variable to store the minimum number of stones Alice can get
            for (int i = 1; i <= 3; i++) {
                // Choose the minimum value between the maximum number of stones Alice can get by choosing the next stone
                mn = min(mn, maxAliceStones(idx + i, !turn));
            }
            // Store the calculated value in dp array and return it
            return dp[idx][turn] = mn;
        }
    }
    
    // Function to determine the winner of the stone game
    string stoneGameIII(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        n = stoneValue.size();
        dp.assign(n, vector<int>(2, -1e9)); // Initialize the dp array with -1e9

        int total = 0; // Variable to store the total sum of stone values
        for (int i = 0; i < n; i++)
            total += stoneValue[i];

        int alice = maxAliceStones(); // Calculate the maximum number of stones Alice can get
        int bob = total - alice; // Calculate the number of stones Bob can get
        vector<string> ans = {"Alice", "Bob", "Tie"}; // Result vector with the possible outcomes
        // Determine the winner based on the number of stones Alice and Bob can get
        return ans[(bob >= alice) + (bob == alice)];
    }
};
