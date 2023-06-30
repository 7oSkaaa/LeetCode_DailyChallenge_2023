// Author: Ahmed Gamal

// for this problem, we can use dynamic programming to solve it
// the approach is similar to the approach of the problem 26- Stone Game II
// the difference is that we will not use the m value, and we will check if that maximum score of the first player is larger than the sum of the rest of the elements or not

class Solution {
    static const int N = 5e4 + 5;
    int memo[N][2];

    int dp(int idx, bool turn, vector<int>& v) {
        if(idx >= v.size()) {
            return 0;
        }

        int& ret = memo[idx][turn];
        if(~ret) {
            return ret;
        }

        // if it's the first player's turn, we will try to maximize the score
        // notice that we are initializing the ret with -2e9 instead of 0 because the maximum score of the first player can be negative
        ret = turn ? -2e9 : 2e9;
        int sum = 0;

        // we will try to choose from 1 to 3 elements from the piles vector
        for(int i = 0; i < 3; i++) {
            if(idx + i >= v.size()) {
                break;
            }
            sum += v[idx + i];
            if(turn) {
                ret = max(ret, sum + dp(idx + i + 1, false, v));
            } else {
                ret = min(ret, dp(idx + i + 1, true, v));
            }
        }

        return ret;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(memo, -1, sizeof memo);

        // the maximum score of the first player
        int ans = dp(0, true, stoneValue);

        // the sum of the elements in the piles vector
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        return ans > sum - ans ? "Alice" : ans < sum - ans ? "Bob" : "Tie";
    }
};