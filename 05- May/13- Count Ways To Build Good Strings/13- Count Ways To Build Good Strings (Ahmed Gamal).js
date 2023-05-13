// Author: Ahmed Gamal

// You are given two integers low and high. Return the number of strings you can build such that:
// The strings are unique and only contain the characters '0' and '1'.
// The strings contain segments of zero zeros and one ones only. (can contain multiple successive segments of the same type).
// The length of each string is between low and high, inclusive.

// This is a simple Counting DP problem. We can use dp[i] to represent the number of good strings that start at index i.
// We can then build the answer by starting at the end of the string and working backwards.
// our base case is dp[i] = 1 for low <= i <= high, since we will have one good string if we end at index i.
// The transition is dp[i] = dp[i] + dp[i + zero] + dp[i + one], since we can append a 0 or 1 to any good string that ends at index i + zero or i + one.
// We can then return dp[0] as our answer.


/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
var countGoodStrings = function(low, high, zero, one) {
    // MOD is the modulo we use to avoid overflow
    const MOD = 1000000007;

    // add two numbers and take the modulo
    let add = (a, b) => (a + b) % MOD;

    // dp[i] is the number of good strings that start at index i (initialized with some additional space to avoid index out of bounds)
    let dp = Array(high << 1 | 1).fill(0);

    // base case: dp[i] = 1 for low <= i <= high
    for(let i = low; i <= high; i++) {
        dp[i] = 1;
    }  

    // transition: dp[i] = dp[i] + dp[i + zero] + dp[i + one]
    for(let i = high; ~i; --i) {
        dp[i] = add(dp[i], add(dp[i + zero], dp[i + one]));
    }

    return dp[0];
};