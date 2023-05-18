// Author: Lama Salah

class Solution {
public:
    // a constant variable mod that is initialized to 1e9+7.
    const int mod = 1e9 + 7;
    int l, r, zero, one, memo[100005];

    int dp(int i = 0){
        // If i is greater than r, then the function returns 0.
        if (i > r) return 0;

        // initialize a reference to an integer variable ans with the value stored in the memo array at the index i.
        int& ans = memo[i];

        // If the value is not equal to -1, then the function returns the value, else set the value of ans equal to zero.
        if (~ans) return ans;
        ans = 0;

       // If i is within the range [l, r], then ans is incremented by 1. Then, the function recursively calls itself with an argument of i+zero and i+one. 
       // The results of these two recursive calls are added to ans.
        ans = (i >= l && i <= r) + ans% mod + dp(i + zero)%mod + dp(i + one)%mod;
        return ans%mod;
    } 

    int countGoodStrings(int low, int high, int zero, int one) {
        this -> l = low; 
        this -> r = high;
        this -> zero = zero;
        this -> one = one;

        // initialize the memo array with -1 values using the memset() function.
        memset(memo, -1, sizeof memo);
        return dp(0);
    }
};
