// Author: Ahmed Gamal

/**
 * @param {number} n
 * @return {number}
 */

// to solve this problem we need to use basic dynamic programming approach (bottom up)
// we can use memoization to solve this problem but it's not necessary
// we can use an array to store the previous values and use them to calculate the next value or we can use 3 variables to store the previous values and use them to calculate the next value
// the next value is the sum of the previous values, so we can use reduce to calculate the sum of the previous values
// we can use the modulo operator to get the index of the array or the variable to store the next value
// the time complexity is O(n) and the space complexity is O(1)
// if the input is less than 3, we can return the input directly without using the loop

var tribonacci = function(n) {
    // initialize the array with the first 3 values (base case)
    let dp = [0, 1, 1];

    // for the input more than 2, we need to calculate the next values
    for(let i = 0; i < n - 2; i++){
        dp[i % 3] = dp.reduce((acc, x) => acc + x);
    }

    // return the value at the index of the input
    return dp[n % 3];
};