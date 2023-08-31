
class Solution{
public:
    int N;
    long dp[10008];
    long help(int i, vector<pair<int, int>> &vp)
    {
        if (vp[i].second == N)
            return 1;
        if (i == vp.size())
            return INT_MAX;
        if (dp[i] != -1)
            return dp[i];
        long ans = INT_MAX;
        for (int j = i + 1; j < vp.size(); j++)
        {
            if (vp[j].first > vp[i].second)
                break;
            ans = min(ans, 1 + help(j, vp));
        }
        return dp[i] = ans;
    }
    int minTaps(int n, vector<int> &ranges)
    {
        N = n;
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> vp;
        for (int i = 0; i < ranges.size(); i++)
        {
            int x = max(0, i - ranges[i]);
            int y = min(n, i + ranges[i]);
            vp.push_back({x, y});
        }
        sort(vp.begin(), vp.end());
        long ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (vp[i].first == 0)
            {
                ans = min(ans, help(i, vp));
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};
