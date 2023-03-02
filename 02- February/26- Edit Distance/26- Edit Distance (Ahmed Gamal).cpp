// Author: Ahmed Gamal

// this is basic edit distance problem
// we can solve it using dp 

// I will use top down dp (memoization)
// dp[i][j] = min number of operations to convert word1[0..i] to word2[0..j]
// if word1[i] == word2[j] then dp[i][j] = dp(i + 1, j + 1) (no operation needed)
// else dp[i][j] = 1 + min(dp(i + 1, j + 1), dp(i + 1, j), dp(i, j + 1))
// dp(i + 1, j + 1) = replace word1[i] with word2[j]
// dp(i + 1, j) = delete word1[i]
// dp(i, j + 1) = insert word2[j] in word1[i]

// base case: if i >= n or j >= m then return n - i + m - j (number of operations needed to convert word1[i..n] to word2[j..m])
// because if i >= n then we need to insert word2[j..m] in word1[i..n]
// and if j >= m then we need to delete word1[i..n]

class Solution {
public:
    int minDistance(string word1, string word2) {
        // n: length of word1
        // m: length of word2
        // memo[i][j] = min number of operations to convert word1[0..i] to word2[0..j] (memoization vector)
        const int n = (int)word1.size(), m = (int)word2.size();
        vector<vector<int>> memo(n + 5, vector<int>(m + 5, -1));

        // dp: dp function (lambda function)
        auto dp = [&](auto dp, int i, int j){
            // base case
            if(i >= n or j >= m){
                return n - i + m - j;
            }

            // memoization (if we already calculated this state before)
            int& ret = memo[i][j];
            if(~ret)
                return ret;
            
            ret = 0;
            if(word1[i] == word2[j]){
                // no operation needed
                ret = dp(dp, i + 1, j + 1);
            }else{
                ret = INT_MAX;

                // replace word1[i] with word2[j]
                ret = min(ret, 1 + dp(dp, i + 1, j + 1));
                
                // delete word1[i]
                ret = min(ret, 1 + dp(dp, i + 1, j));
                
                // insert word2[j] in word1[i]
                ret = min(ret, 1 + dp(dp, i, j + 1));
            }

            return ret;
        };

        // call dp function
        return dp(dp, 0, 0);
    }
};