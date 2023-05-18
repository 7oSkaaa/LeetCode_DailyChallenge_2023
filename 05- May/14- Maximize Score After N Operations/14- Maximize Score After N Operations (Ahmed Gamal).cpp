// Author: Ahmed Gamal

// for this problem we will use dp on subsets (memoization) (using bitmask)
// the idea is to try all possible pairs of numbers and try to add them to the final answer
// we will use dp[msk] to be the maximum score we can get from the remaining numbers in the array if we already used the numbers in the mask
// we will try to add two numbers to the answer and continue building the rest of the answer
// to get the number of the operation we are in, we will use the number of ones in the mask
// every operation we will take two numbers and mark them as used in the mask, so the number of ones in the mask will be the number of operations we did * 2
// to get the current operation we are in, we will divide the number of ones in the mask by 2 after adding 2 to it (the two elements we are going to use in the current operation)

class Solution {
    // N: the maximum number of elements in the array
    // memo: the dp array
    static const int N = 14;
    int memo[1 << N | 1], n;
    vector<int> v;

    // dp(msk): the maximum score we can get from the remaining numbers in the array if we already used the numbers in the mask (msk
    int dp(int msk) {
        // if we already used all the numbers in the array, we will return 0
        if(__builtin_popcount(msk) == n) {
            return 0;
        }

        // if we already calculated the answer, we will return it
        int& ret = memo[msk];
        if(~ret) {
            return ret;
        }

        // op: the current operation we are in
        int op = (__builtin_popcount(msk) + 2) / 2;

        ret = 0;

        // we will try to add two numbers to the answer and continue building the rest of the answer
        for(int i = 0; i < n; i++) {
            // if we already used the number i, we will skip it
            if(msk & (1 << i))
                continue;

            // cur: the mask of the current element we are going to use
            int cur = 1 << i;

            // we will try to add the number i to the answer and continue building the rest of the answer
            for(int j = i + 1; j < n; j++) {

                // if we already used the number j, we will skip it
                if(msk & (1 << j))
                    continue;

                // we will try to add the number j to the answer and continue building the rest of the answer
                ret = max(ret, op * __gcd(v[i], v[j]) + dp(msk | cur | (1 << j)));
            }
        }

        return ret;
    }
public:
    int maxScore(vector<int>& nums) {
        // n: the number of elements in the array
        // v: the array of numbers
        n = int(nums.size());
        v = nums;

        // initialize the dp array with -1
        memset(memo, -1, sizeof memo);

        // we will start building the answer from the first operation
        return dp(0);
    }
};