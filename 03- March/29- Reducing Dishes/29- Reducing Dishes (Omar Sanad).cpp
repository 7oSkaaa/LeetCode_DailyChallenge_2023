// Author: Omar Sanad

class Solution {
public:
    int n, dp[505][505];
    vector<int> sat;    // satisfaction vector
    int rec(int idx, int currTime) {
        if (idx == n)   return 0;   // when reaching the end of the vector
        int &ret = dp[idx][currTime];
        if (~ret)   return ret;
        ret = rec(idx + 1, currTime);   // leave
        ret = max(ret, sat[idx] * currTime + rec(idx + 1, currTime + 1));   // take;
        return ret;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        sat = satisfaction;
        memset(dp, -1, sizeof(dp));
        return rec(0, 1);
    }
};
