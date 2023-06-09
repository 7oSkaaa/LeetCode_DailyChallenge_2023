// Author: Ahmed Gamal

// for this problem we will use dp with memoization
// we will try all possible cuts and we will try to minimize the cost
// to achieve that and avoid overlapping subproblems we will use memoization

// each cut is responsible for a range of the stick, we can keep track of that range by keeping the left and right bounds of the range

class Solution {
    // N: max number of cuts
    // memo: dp memoization table
    // v: vector of cuts
    static const int N = 101;
    int memo[N][N];
    vector<int> v;


    // dp(a, b, l, r) returns the minimum cost to cut the stick which has the range [l, r] and the cuts are in the range of indices [a, b]
    int dp(int a, int b, int l, int r) {
        // base case
        if(a > b) {
            return 0;
        }

        // if we already calculated this state
        int& ret = memo[a][b];
        if(~ret) {
            return ret;
        }

        // try all possible cuts from a to b
        ret = 2e9;
        for(int i = a; i <= b; i++) {
            // the cost of this cut is the length of the stick (excluding l)
            ret = min(ret, r - l + dp(a, i - 1, l, v[i]) + dp(i + 1, b, v[i], r));
        }

        return ret;
    }

public:
    
    int minCost(int n, vector<int>& cuts) {
        // initialize memoization table
        memset(memo, -1, sizeof memo);

        // sort the cuts
        v = cuts;
        sort(v.begin(), v.end());

        return dp(0, cuts.size() - 1, 0, n);   
    }
};