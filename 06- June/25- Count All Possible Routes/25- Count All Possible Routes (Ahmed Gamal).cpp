// Author: Ahmed Gamal

// for this problem we can use dp to solve it
// we can define dp[i][rem] is the number of ways to reach the finish point from the current point i with remaining fuel rem
// from each point we can go to any other point if we have enough fuel
// we can use memoization to avoid recomputing the same state again
// the base case is if we have no fuel we can't move
// if we are in the finish point we add 1 to the answer and continue if we have remaining fuel

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // MOD: 1e9 + 7 to avoid overflow
        // memo[i][rem] is the number of ways to reach the finish point from the current point i with remaining fuel rem
        const int MOD = 1e9 + 7;
        int memo[101][202];
        
        memset(memo, -1, sizeof memo);

        // dp function
        auto dp = [&](auto dp, int i, int rem) -> int {
            // invalid state
            if(rem < 0) {
                return 0;
            }

            // base case
            if(not rem) {
                return i == finish;
            }

            // if we have already computed this state before
            int& ret = memo[i][rem];
            if(~ret) {
                return ret;
            }

            // if we are in the finish point we add 1 to the answer and continue if we have remaining fuel
            ret = i == finish;

            // try to go to any other point if we have enough fuel
            for(int j = 0; j < locations.size(); j++) {
                if(j == i) {
                    continue;
                }
                int wt = abs(locations[j] - locations[i]);
                ret += dp(dp, j, rem - wt);
                ret %= MOD;
            }

            return ret;
        };

        return dp(dp, start, fuel);
    }
};