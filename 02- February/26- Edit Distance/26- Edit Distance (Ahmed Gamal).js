// Author: Ahmed Gamal

// this is the same solution as the one in C++ but in JS (I just changed the syntax and used bottom-up approach instead of top-down)
// for more details about the solution, please refer to the C++ solution: https://github.com/AhmedGamal2212/LeetCode_DailyChallenge_2023/blob/main/02-%20February/26-%20Edit%20Distance/26-%20Edit%20Distance%20(Ahmed%20Gamal).cpp

/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    // n: length of word1
    // m: length of word2
    // dp[i][j]: minimum number of operations to convert word1[i:] to word2[j:]
    const n = word1.length, m = word2.length;
    let dp = Array(n + 5).fill(0).map(x => Array(m + 5).fill(0));

    // initialize the base cases
    for(let i = 0; i <= n; i++){
        dp[i][m] = n - i;
    }
    for(let j = 0; j <= m; j++){
        dp[n][j] = m - j;
    }

    // bottom-up approach
    for(let i = n - 1; ~i; i--){
        for(let j = m - 1; ~j; j--){
            if(word1[i] === word2[j]){
                dp[i][j] = dp[i + 1][j + 1];
            }else{
                dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]);
            }
        }
    }

    // the answer is located at dp[0][0]
    return dp[0][0];
};