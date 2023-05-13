// author : Omar Sanad

class Solution {
public:
    // declare the variables inside the class itself to be able to use it anywhere in the class
    // also declare a 2D array for memoization
    int low, high, zero, one, dp[100001][2];

    // recursion function, takes two parameters the current position and the last used charecter '1' or '0'
    int rec(int idx, bool last_is_one) {
        // if we exceeded the allowed limit, then we return
        if (idx > high)
            return 0;

        // assign the dp[idx][last_is_one] by reference, for clean code
        int &ret = dp[idx][last_is_one];

        // if the answer for this state has been already calculated, then return its value which is stored in the dp
        if (~ret)   return ret;

        // otherwise, then we have to calculate this state,
        // if we are in the allowed range (low <= idx <= high), then count this state as valid
        ret = idx >= low and idx <= high;
        
        // try to take zeros
        ret = (ret + rec(idx + one, true)) % int(1e9 + 7);

        // try to take ones
        ret = (ret + rec(idx + zero, false)) % int(1e9 + 7);

        // return the answer of this state
        return ret;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // assign the passed parameters to the variables declared in the class itself
        this->low = low;
        this-> high = high;
        this->zero = zero;
        this->one = one;

        // initialize the dp with -1, mark as not calculated
        memset(dp, -1, sizeof(dp));

        // return the answer to the problem
        return rec(0, true);        
    }
};
