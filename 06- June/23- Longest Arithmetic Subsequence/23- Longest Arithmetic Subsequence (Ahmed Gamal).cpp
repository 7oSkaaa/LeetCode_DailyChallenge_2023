// Author: Ahmed Gamal

// for this problem, we can use dynamic programming to solve it
// this is the same problem as the longest increasing subsequence problem but with a little change
// the change is that we need to find the sequence as arithmetic sequence, so we need to store the difference between the elements
// and we need to store the length of the sequence for each difference
// dp[i][d] is the length of the sequence that ends at index i with difference d
// and because the difference can be negative, we need to add the maximum value in the array to the difference to make it non-negative

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // n: the number of elements in the array
        // mx: the maximum value in the array
        // dp[i][d]: the length of the sequence that ends at index i with difference d
        const int n = int(nums.size());
        const int mx = *max_element(nums.begin(), nums.end());
        vector dp(n, vector<int>(mx << 1 | 1, 1));

        // ans: the answer (initially 1 because the minimum length is 1)
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + mx;
                dp[i][d] = max(dp[j][d] + 1, dp[i][d]);
                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};