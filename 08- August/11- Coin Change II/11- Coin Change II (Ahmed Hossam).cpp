// Author: Ahmed Hossam

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Create a vector 'dp' to store the count of combinations for each amount from 0 to 'amount'
        vector < int > dp(amount + 1);
        
        // There is only one way to make 0 amount, which is by not using any coins
        dp[0] = 1;
        
        // Iterate through each coin in the 'coins' vector
        for(auto& coin : coins)
            // Iterate through each possible amount starting from 1 up to 'amount'
            for(int money = 1; money <= amount; money++)
                // Check if the current coin value is less than or equal to the current amount
                if(money >= coin)
                    // Increment the count of combinations for the current amount by the count of combinations for (current amount - coin value)
                    dp[money] += dp[money - coin];
        
        // Return the count of combinations to make the given 'amount'
        return dp[amount];
    }
};
