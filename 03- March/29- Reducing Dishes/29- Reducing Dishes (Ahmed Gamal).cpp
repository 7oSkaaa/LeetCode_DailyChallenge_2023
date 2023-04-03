// Author: Ahmed Gamal

// for this problem, we want to find the maximum total sum of the dishes after removing some dishes (can be none)
// we can use dp to solve this problem, but we need to find the recurrence relation
// dp[i][j]: the maximum total sum of the dishes after taking a subset of the first i of length j - 1
// dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + satisfaction[i - 1] * j)
// the answer is max(dp[n][j]) for all j

// but since we can take any subset of the dishes in any order, and taking a dish will not affect the total sum of the other dishes, we can sort the dishes in non-increasing order
// this enables us to make sure that we will always take the dishes with highest satisfaction possible

class Solution {
    // memo[i][j]: the maximum total sum of the dishes after taking a subset of the first i of length j - 1
    vector<vector<int>> memo;
public:

    int dp(int idx, int curr, vector<int>& satisfaction) {
        // if we reached the end of the dishes, then the maximum total sum is 0
        if(idx >= satisfaction.size()) {
            return 0;
        }

        // if we have already calculated the answer, then return it
        int& ret = memo[idx][curr];
        if(~ret) {
            return ret;
        }

        // take the current dish or not
        ret = dp(idx + 1, curr, satisfaction);
        ret = max(ret, satisfaction[idx] * curr + dp(idx + 1, curr + 1, satisfaction));

        return ret;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        const int n = (int)satisfaction.size();
        memo.assign(n + 1, vector<int>(n + 1, -1));

        // sort the dishes in non-increasing order
        sort(satisfaction.begin(), satisfaction.end());

        // the answer is dp(0, 1)
        return dp(0, 1, satisfaction);
    }
};