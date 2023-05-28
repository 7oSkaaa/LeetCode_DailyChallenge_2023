// Author: Ahmed Gamal

// for this problem, we can use dynamic programming to solve it
// we will solve the problem from the perspective of the first player (Alex)
// from the perspective of the first player, in his turn, he will try to maximize the score
// and in the second player's turn, he will try to minimize the score of the first player

// so, we will use a memoization table to store the maximum score that the first player can get from the ith element in the piles vector
// and the m value is m

class Solution {
    // memoization table and it's size
    static const int N = 101;
    int memo[N][N][2];

    // dp(idx, m, turn) returns the maximum score that the first player can get from the idx element in the piles vector
    // and the m value is m and it's the turn of the turn ? the first player : the second player
    int dp(int idx, int m, int turn, vector<int>& v) {
        // if the idx is larger than the size of the piles vector, we will return 0
        if(idx >= v.size()) {
            return 0;
        }

        // if the value of the memoization table is not -1, we will return it
        int& ret = memo[idx][m][turn];
        if(~ret) {
            return ret;
        }

        // if it's the first player's turn, we will try to maximize the score
        // if it's the second player's turn, we will try to minimize the score
        ret = turn ? 0 : 2e9;

        // we will try to choose from 1 to 2 * m elements from the piles vector
        // sum is the sum of the elements that we will choose
        int sum = 0;
        for(int i = 0; i < m * 2; i++) {
            // if the idx + i is larger than the size of the piles vector, we will break
            if(idx + i >= v.size()) {
                break;
            }

            // updating the sum
            sum += v[idx + i];

            // if it's the first player's turn, we will try to maximize the score
            if(turn) {
                ret = max(ret, sum + dp(idx + i + 1, max(m, i + 1), false, v));
            } else {
                // if it's the second player's turn, we will try to minimize the score
                ret = min(ret, dp(idx + i + 1, max(m, i + 1), true, v));
            }
        }

        return ret;
    }

public:
    int stoneGameII(vector<int>& piles) {
        // initializing the memoization table with -1
        memset(memo, -1, sizeof memo);

        // starting the dp from the first element in the piles vector with m = 1 and it's the first player's turn
        return dp(0, 1, true, piles);
    }
};