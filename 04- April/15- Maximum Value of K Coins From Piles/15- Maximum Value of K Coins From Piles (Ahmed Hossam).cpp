// Author: Ahmed Hossam

class Solution {
public:
   
    // This macro is used to get the size of a container 
    #define sz(x) int(x.size())

    // Function to find the maximum value of coins that can be obtained
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        // Dynamic programming table to store the maximum value of coins that can be obtained for each state
        vector < vector < int > > dp(n + 1, vector < int > (k + 1));
        
        // Loop through all the possible remaining values of coins
        for(int remain = 0; remain <= k; remain++){
            // Loop through all the piles from right to left
            for(int i = n - 1; ~i; i--){
                // The maximum value of coins that can be obtained if we don't take any coins from this pile
                dp[i][remain] = dp[i + 1][remain];

                // Loop through all the possible number of coins that can be taken from this pile
                for(int take = 1, sum = 0; take <= min(remain, sz(piles[i])); take++){
                    // Calculate the total value of the coins taken
                    sum += piles[i][take - 1];
                    
                    // Update the maximum value of coins that can be obtained for this state
                    dp[i][remain] = max(dp[i][remain], sum + dp[i + 1][remain - take]);
                }
            }
        }

        // Return the maximum value of coins that can be obtained for the initial state
        return dp[0][k];
    }
};
