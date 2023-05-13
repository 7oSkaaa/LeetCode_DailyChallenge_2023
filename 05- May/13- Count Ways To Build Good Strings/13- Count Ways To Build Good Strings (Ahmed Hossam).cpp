// Author: Ahmed Hossam

class Solution {
public:
    // Set the value of the constant MOD to 1e9+7
    static constexpr int MOD = 1e9 + 7;

    // Function that adds a value to another and checks if the result is greater than or equal to MOD
    void add(int& ret, int to_add){
        ret += to_add;
        if(ret >= MOD)
            ret -= MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Initialize a vector called dp with size equal to high + 1
        vector < int > dp(high + 1);
        
        // Set the first element of dp to 1
        dp[0] = 1;
        
        // Initialize a variable called sum to 0
        int sum = 0;
        
        for(int i = 1; i <= high; i++){
            // If i is greater than or equal to zero, add the value of dp[i-zero] to dp[i]
            if(i >= zero)
                add(dp[i], dp[i - zero]);
            
            // If i is greater than or equal to one, add the value of dp[i-one] to dp[i]
            if(i >= one)
                add(dp[i], dp[i - one]);
            
            // If i is greater than or equal to low, add the value of dp[i] to sum
            if(i >= low)
                add(sum, dp[i]);
        }

        // Return the value of sum
        return sum;
    }
};
