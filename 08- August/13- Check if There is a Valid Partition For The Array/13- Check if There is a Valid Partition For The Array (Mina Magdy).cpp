// Author: Mina Magdy

class Solution {
public:
    // Function to check if the given nums array can be partitioned validly
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1); // Create a DP array to store valid partition status
        dp[0] = 1; // Base case: an empty partition is valid

        // Loop over array starting from index 2
        for (int i = 2; i <= n; i++) {
            if (i > 2) {
                // Find the maximum and minimum values among the last 3 elements
                auto [mx, mn] = minmax({nums[i - 1], nums[i - 2], nums[i - 3]});
                
                // Check two conditions for validity of partition
                dp[i] = dp[i] || (dp[i - 3] && (mx == mn));
                dp[i] = dp[i] || (dp[i - 3] && (nums[i - 2] + 1 == nums[i - 1] && nums[i - 2] - 1 == nums[i - 3]));
            }
            // Check condition for validity of partition
            dp[i] = dp[i] || (dp[i - 2] && (nums[i - 1] == nums[i - 2]));
        }
        
        return dp[n]; // Return whether the entire array can be validly partitioned
    }
};
