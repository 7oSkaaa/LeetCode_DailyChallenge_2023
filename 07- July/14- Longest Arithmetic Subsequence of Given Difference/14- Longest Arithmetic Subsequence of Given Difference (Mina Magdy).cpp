// Author: Mina Magdy

class Solution {
public:
    // Function to find the longest subsequence with a common difference 'd'
    int longestSubsequence(vector<int>& arr, int d) {
        // Calculate the offset value to ensure that all array elements are non-negative
        int offset = max(-*min_element(arr.begin(), arr.end()), 0);

        // Find the maximum element in the array
        int mx = *max_element(arr.begin(), arr.end());

        // Create a DP (dynamic programming) array with size mx + offset + 1, initialized with 0
        vector<int> dp(mx + offset + 1, 0);

        // Initialize the answer variable to 0
        int ans = 0;

        // Iterate over each element in the array
        for (int i = 0; i < arr.size(); i++) {
            int j = arr[i] + offset; // Adjust the current element to the index in the DP array

            // Check if the adjusted index is within the bounds of the DP array
            if (j < dp.size()) {
                // Calculate the length of the subsequence with the common difference 'd'
                dp[j] = 1 + (j - d >= 0 && j - d < dp.size() ? dp[j - d] : 0);

                // Update the answer with the maximum subsequence length
                ans = max(ans, dp[j]);
            }
        }

        // Return the maximum subsequence length
        return ans;
    }
};
