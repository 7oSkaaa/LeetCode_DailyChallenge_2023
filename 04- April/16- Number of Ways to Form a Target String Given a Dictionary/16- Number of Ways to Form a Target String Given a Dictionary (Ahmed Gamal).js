// Author: Ahmed Gamal

// this is the iterative solution for this problem
// for the recursive solution and the explanation of the problem check my other solution in the same folder
// this solution is based on the idea of the recursive solution but it is implemented iteratively

/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */
var numWays = function(words, target) {
    // n is the length of each word
    // k is the length of the target string
    // MOD is the modulo value
    const n = words[0].length;
    const k = target.length;
    const MOD = 1000000007;

    // add function to add two numbers and return the result modulo MOD
    let add = (a, b) => {
        return (a + b) % MOD;
    };

    // freq[i][j] is the number of times the letter j appears in the ith position of all words
    
    // dp[i][j] is the number of ways to form the substring of target from index j to the end if we are at the ith row of the freq array
    // dp[i][j] = dp[i + 1][j] + j < k ? dp[i + 1][j + 1] * freq[i][target[j] - 'a'] : 0

    // from the transition function we can see that we only need the dp[i + 1] row to calculate the dp[i] row
    // and we only need to take the previous value of dp[i][j] and the value of dp[i][j + 1] to calculate the current value of dp[i][j]
    // so we can use a 1D array to store the dp values and update it in each iteration

    let freq = Array(n).fill(0).map(x => Array(26).fill(0));
    let dp = Array(k + 5).fill(0);

    // calculate the freq array
    words.forEach(word => {
        for(let i = 0; i < n; i++) {
            freq[i][word.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        }
    });

    // initialize the base case
    dp[k] = 1;

    // iterate over the freq array from the last row to the first row
    for(let i = n - 1; ~i; --i) {
        // iterate over the dp array from the first column to the last column
        for(let j = 0; j <= k; j++) {
            // if j < k then we can take the current value of dp[j] and add to it the value of dp[j + 1] * freq[i][target[j] - 'a']
            if(j < k) {
                dp[j] = add(dp[j], dp[j + 1] * freq[i][target.charCodeAt(j) - 'a'.charCodeAt(0)]);
            }
        }
    }

    // return the value of dp[0]
    return dp[0];
};