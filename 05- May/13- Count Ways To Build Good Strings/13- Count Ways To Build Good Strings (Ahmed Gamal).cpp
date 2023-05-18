// Author: Ahmed Gamal

// for this problem we will use dp (memoization)
// the idea will be the same as the iterative solution, you can see the iterative solution for more details about the idea
// we will use dp[i] to be the number of good strings we can build from i to n (n is any number in the range [low, high])

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // MOD is the modulo we will use to avoid overflow
        // memo is the dp array we will use to store the number of good strings we can build from i to n
        const int MOD = 1e9 + 7;
        vector<int> memo(high + 5, -1);
        
        // add is a lambda function to add two numbers and take the modulo
        auto add = [&](int& a, int b) -> void {
            a += b;
            if(a >= MOD) {
                a -= MOD;
            }
        };
        
        // dp is a lambda function to calculate the number of good strings we can build from i to n
        auto dp = [&](auto dp, int len) -> int {
            // if we reach the end of the string, we will return 1 if the length is in the range [low, high] and 0 otherwise
            if(len >= high) {
                return len == high;
            }

            // if we already calculated the number of good strings we can build from i to n, we will return it
            int& ret = memo[len];
            if(~ret) {
                return ret;
            }

            // ret will be the number of good strings we can build from i to n
            // before we add the number of good strings we can build from i to n, we will check if the length is in the range [low, high]
            // if the length is in the range, then we have a good string, so we will add 1 to the number of good strings we can build and continue building the rest of it
            ret = len >= low;

            // we will try to add a zero and a one to the string and continue building the rest of it
            add(ret, dp(dp, len + zero));
            add(ret, dp(dp, len + one));

            return ret;
        };

        // we will start building the string from the first character
        return dp(dp, 0);
    }
};