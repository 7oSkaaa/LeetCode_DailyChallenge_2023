// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to count the number of ways to build a string of length between low and high
    // we will use dp to count the number of ways to build a string of length n
    // we will use a recursive function to count the number of ways to build a string of length n
    // the recursive function will return 0 if n > high


    // dp: dp[i] -> number of ways to build a string of length i
    // low: the minimum length of the string
    // high: the maximum length of the string
    // zero: the number of zeros you can append to the string
    // one: the number of ones you can append to the string
    int dp[100005], low, high, zero, one, mod = 1e9 + 7;

    // recursive function to count the number of ways to build a string of length n
    int cnt_ways(int n){
        // if n > high return 0
        if(n > high) return 0;

        // if n is calculated before return the value
        if(dp[n] != -1) return dp[n];

        // if n is in the range [low, high] then add 1 to the answer
        int ans = (n >= low);

        // add the number of ways to build a string of length n + zero
        ans += cnt_ways(n + zero);
        ans %= mod;
        // add the number of ways to build a string of length n + one
        ans += cnt_ways(n + one);
        ans %= mod;

        // return the answer
        return dp[n] = ans;
    }

    int countGoodStrings(int low, int high, int zero, int one){
        // initialize dp with -1
        memset(dp, -1, sizeof(dp));
        // initialize the global variables    
        this -> low = low, this -> high = high, this -> zero = zero, this -> one = one;

        // return the number of ways to build a string of length between low and high starting from length 0
        return cnt_ways(0);
    }
};
