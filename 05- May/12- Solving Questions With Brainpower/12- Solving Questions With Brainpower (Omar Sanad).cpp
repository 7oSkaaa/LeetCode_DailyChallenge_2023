// author : Omar Sanad

class Solution {
public:
    // define a macro ll for long long
    #define ll long long
    
    // declaring the qu 2d vector (this is the 2d vec passed by the function)
    vector < vector < int > > qu;

    // declaring a 1D array for memoizing the dp
    ll dp[100001];

    // the recursion function
    ll rec(int idx) {

        // if we have finished all elements in the qu, then return
        if (idx >= qu.size())   return 0;

        ll &ret = dp[idx];
        if (~ret)   return ret;

        ret = rec(idx + 1); // leave

        ret = max(ret, qu[idx][0] + rec(idx + qu[idx][1] + 1)); // take

        return ret;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));

        qu = questions;

        return rec(0);
    }
};
