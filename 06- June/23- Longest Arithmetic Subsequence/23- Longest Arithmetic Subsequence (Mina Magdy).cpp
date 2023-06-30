// Author: Mina Magdy

class Solution {
public:
    // Function to find the longest arithmetic subsequence length
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        vector<vector<int>> dp(n, vector<int>(1002, 1)); // Create a 2D DP array initialized to 1
        int ans = 1; // Initialize the answer variable to 1
        
        // Iterate over each element in the input vector
        for (int i = 0; i < n; i++) {
            // Iterate over the elements before the current element
            for (int j = 0; j < i; j++) {
                // Compute the difference between the current element and the previous element
                int diff = nums[i] - nums[j] + 500;
                
                // Update the current DP value with the maximum of its current value
                // or 1 plus the DP value of the previous element with the same difference
                dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
                
                // Update the answer variable with the maximum of its current value
                // or the current DP value
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans; // Return the maximum length of the arithmetic subsequence
    }
};
