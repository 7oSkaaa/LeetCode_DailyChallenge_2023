// Author: Ahmed Gamal

/**
 * @param {number[]} nums
 * @return {number}
 */

// for this problem we can use dp to minimize the number of jumps to reach the end
// dp[i] = min(dp[i], dp[j] + 1) where j is each length of the jump from 1 to nums[i] and i + j < n
// the answer will be dp[n - 1] (minimum number of jumps to reach the n - 1 index)

var jump = function(nums) {
    // n: length of nums
    const n = nums.length;
    // dp: array to store the minimum number of jumps to reach each index
    let dp = Array(n).fill(Infinity);
    
    // base case (minimum number of jumps to reach the 0 index is 0)
    dp[0] = 0;

    // loop over the array
    for(let i = 0; i < n; i++){
        // loop over the jumps from 1 to nums[i]
        for(let j = 1; j <= nums[i] && i + j < n; j++){
            // update the minimum number of jumps to reach the current index
            dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
        }
    }

    // return the minimum number of jumps to reach the n - 1 index
    return dp[n - 1];
};