// Author: Ahmed Gamal

// for this problem we will use dp to find the longest palindromic subsequence
// the longest palindromic subsequence of a string is the longest common subsequence of the string and its reverse
// so we will use the longest common subsequence algorithm to find the longest palindromic subsequence 
// we will use rolling array to reduce the space complexity

/**
 * @param {string} s
 * @return {number}
 */
var longestPalindromeSubseq = function(s) {
    // n: length of the string
    // dp: dp array (previous row)
    // t: reverse of the string
    const n = s.length;
    let dp = Array(n + 1).fill(0);
    let t = s.split('').reverse().join('');

    for(let i = 1; i <= n; i++) {
        // dp_: dp array (current row)
        let dp_ = Array(n).fill(0);
        for(let j = 1; j <= n; j++) {
            // if the current character in the string is equal to the current character in the reverse of the string
            if(s[i - 1] === t[j - 1]) {
                // update dp[i][j] with dp[i - 1][j - 1] + 1
                dp_[j] = dp[j - 1] + 1;
            } else {
                // update dp[i][j] with the maximum between dp[i - 1][j] and dp[i][j - 1]
                dp_[j] = Math.max(dp[j], dp_[j - 1]);
            }
        }
        // swap dp and dp_ to use the current row as the previous row in the next iteration
        [dp, dp_] = [dp_, dp];
    }

    // return the last element in the dp array
    return dp[n];
};