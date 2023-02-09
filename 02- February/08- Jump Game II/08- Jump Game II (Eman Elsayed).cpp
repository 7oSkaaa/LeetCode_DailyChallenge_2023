// author : Eman Elsayed

int n;
vector<long long> dp;
class Solution
{
public:
    // iterative solution
    int jump(vector<int> &nums)
    {
        n = nums.size();
        dp.assign(20001, INT_MAX); // fill the dp with max value
        dp[n - 1] = 0;             // except the last element because it's the destination
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                dp[i] = min(1 + dp[i + j], dp[i]); // find optimal solution for each dp[i]
            }
        }
        return dp[0]; // return the minimum number of jumps to reach the destination
    }
};

// Another solution using Recursive solution
long long dp[10001];
class Solution
{
public:
    long long solve(int idx, vector<int> &nums)
    {
        if (idx >= nums.size() - 1)
            return 0;             // base case
        long long &ret = dp[idx]; // memoization
        if (~ret)
            return ret; // if the value is calculated before return it
        ret = INT_MAX;  // if the value is not calculated before fill it with max value
        for (int j = 1; j <= nums[idx]; j++)
        {
            ret = min(solve(idx + j, nums) + 1, ret); // find minimum number of jumps to reach the destination
        }
        return ret;
    }

    long long jump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp)); // fill the dp with -1
        return solve(0, nums);      // call the recursive function
    }
};