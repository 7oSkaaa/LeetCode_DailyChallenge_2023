// Author: Ahmed Gamal

// for this problem, we need to find the number of ways to restore the array
// we can use dp to solve it
// we can try all the cases where we can split the string into parts
// if the part is a valid number (between 1 and k), then we can solve the problem for the rest of the string
// otherwise, we can't split the string into parts and the answer is 0

class Solution {
    // MOD: modulo
    // memo: dp array
    static const int MOD = 1e9 + 7;
    vector<int> memo;

    // dp(idx, s, k): number of ways to restore the array from the substring starting at idx
    int dp(int idx, string& s, int k) {
        // base case
        if(idx >= s.size()) {
            return 1;
        }

        // if we have already calculated the answer, then return it
        int& ret = memo[idx];
        if(~ret) {
            return ret;
        }

        // try all the cases where we can split the string into parts
        ret = 0;

        // num: the number we are trying to split the string into
        long long num = 0;
        // the max length of the number is 10 (1e9) and we need to check if the index is valid
        for(int i = 1; i <= 10 and idx + i <= s.size(); i++) {
            // add the next digit to the number
            num = num * 10 + (s[idx + i - 1] - '0');
            // if the number is not valid, then we can't split the string into parts
            if(num > k or num < 1) {
                break;
            }

            // if the part is a valid number (between 1 and k), then we can solve the problem for the rest of the string
            ret += dp(idx + i, s, k);
            ret %= MOD;
        }

        // return the answer
        return ret;
    }

public:
    int numberOfArrays(string s, int k) {
        // initialize the variables
        memo = vector<int>(s.size(), -1);

        // return the answer
        return dp(0, s, k);
    }
};