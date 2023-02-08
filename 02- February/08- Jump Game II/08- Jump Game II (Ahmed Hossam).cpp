// Author: Ahmed Hossam

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector < int > dp(n + 1, 1e9);

        // base case for dp
        dp[n - 1] = 0;
        
        // for each dp[i] calculate minmum move to reach it
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j <= nums[i] && j + i <= n - 1; j++)
                dp[i] = min(dp[i], 1 + dp[i + j]);

        //  the minimum number of jumps
        return dp[0];
    }
};
