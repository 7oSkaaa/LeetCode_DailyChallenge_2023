// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the maximum score we can get after n operations
    // we can do that using dp and bitmasking
    // we need to find the way to rearrange the numbers to get the maximum score
    // we can use bitmasking to represent the numbers we have used
    // we can use dp[mask][prev] to be the maximum score we can get if we have used the numbers in mask and the last number we have used is prev
    // we can use a recursive function to get the maximum score


    // dp: dp[mask][prev] -> maximum score we can get if we have used the numbers in mask and the last number we have used is prev
    vector<vector<int>> dp;
    // nums: vector of numbers
    vector<int> nums;
    // n: number of elements
    int n;

    // function to get the maximum score
    int get_max(int mask, int prev, int idx){
        // if we have used all numbers return 0
        if((1 << n) - 1 == mask) return 0;

        // if we have already calculated the answer for this state return it
        if(dp[mask][prev] != -1) return dp[mask][prev];

        // ans: maximum score we can get
        int ans = 0;

        // iterate over all numbers
        for(int i = 0; i < n; i++){
            // if the number is not used
            if(!((1 << i) & mask)){
                // calculate the maximum score, if there is no previous number we add 0 to the score and if there is a previous number we add the gcd of the two numbers multiplied by idx
                ans = max(ans, (prev != n ? gcd(nums[i], nums[prev]) * idx : 0) + get_max(mask | (1 << i), (prev == n ? i : n), idx + (prev != n)));
            }
        }

        // return the answer
        return dp[mask][prev] = ans;
    }   


    int maxScore(vector<int>& nums) {
        // initialize the variables
        this -> n = nums.size();
        this -> nums = nums;

        // initialize dp with -1
        dp.assign(1 << n, vector<int> (n + 1, -1));

        // return the maximum score
        return get_max(0, n, 1);
    }
};
