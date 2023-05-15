// Author: Ahmed Hossam

class Solution {
public:

    // declare variables
    int n, full_mask;
    // vectors to store numbers and dynamic programming results
    vector<int> nums, dp;

    // function to check if a bit is empty in a binary mask
    bool is_empty_bit(int bit, int mask){
        return !(mask & (1 << bit));
    }

    // recursive function to calculate the maximum score
    int max_score(int mask){
        // if all bits are filled, return 0
        if(mask == full_mask) return 0;
        // use memoization to avoid redundant computations
        int& ret = dp[mask];
        // calculate the current index based on the number of filled bits
        int idx = __builtin_popcount(mask) / 2 + 1;
        // if the result has already been calculated, return it
        if(~ret) return ret;
        ret = 0;
        // iterate over all pairs of numbers
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                // if both numbers are empty, calculate the score
                if(is_empty_bit(i, mask) && is_empty_bit(j, mask))
                    ret = max(ret, (idx * __gcd(nums[i], nums[j])) + max_score(mask | (1 << i) | (1 << j)));
        // return the maximum score
        return ret;
    }

    int maxScore(vector<int>& nums) {
        // set the number of elements
        n = nums.size();
        // set the vector of numbers
        this -> nums = nums;
        // set the full binary mask
        full_mask = (1 << n) - 1;
        // initialize the dynamic programming vector with -1
        dp = vector<int>(1 << n, -1);
        // return the maximum score starting with an empty mask
        return max_score(0);
    }
};
