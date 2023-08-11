// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the number of combinations to make 'amount' using given 'coins'
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0); // Initialize an array 'dp' to store combinations for each amount
        dp[0] = 1; // Base case: There is one way to make amount 0, i.e., by not selecting any coin
        
        // Loop over each coin
        for (int j = 0; j < coins.size(); j++) {
            // Loop over each amount starting from 1
            for (int i = 1; i <= amount; i++) {
                // If the current coin can be used to make the current amount 'i'
                if (i - coins[j] >= 0)
                    dp[i] += dp[i - coins[j]]; // Accumulate combinations
            }
        }
        
        return dp[amount]; // Return the total number of combinations to make 'amount'
    }
};
