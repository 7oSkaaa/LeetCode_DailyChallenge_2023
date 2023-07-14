// Author: Ahmed Hossam

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // N is a constant representing a large number.
        constexpr int N = 2e4;

        // dp is a vector of integers with size 2 * N + 5.
        // It is used to store the dynamic programming values.
        vector < int > dp(2 * N + 5);

        // Iterate through each element x in the input vector arr.
        for (auto& x : arr)
            // Calculate the index for the current element x in the dp vector by adding N.
            // Update the value at the calculated index in the dp vector by taking the maximum
            // between the current value and the value at index x - difference + N + 1.
            dp[x + N] = max(dp[x + N], dp[x - difference + N] + 1);

        // Return the maximum element in the dp vector.
        return *max_element(dp.begin(), dp.end());
    }
};
