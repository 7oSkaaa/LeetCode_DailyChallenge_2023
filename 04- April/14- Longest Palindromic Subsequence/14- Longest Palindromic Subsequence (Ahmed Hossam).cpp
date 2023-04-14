// Author: Ahmed Hossam

class Solution {
public:
    int longestPalindromeSubseq(const string& s) {
        // Store the size of the given string
        int sz = s.size();

        // Create a 2D vector with size (sz + 5) * (sz + 5) and initialize all elements to 0
        vector < vector < int > > dp(sz + 5, vector < int > (sz + 5));

        // Loop through all possible pairs of (i, j) where 1 <= i, j <= sz
        for(int i = 1; i <= sz; i++) {
            for(int j = 1; j <= sz; j++) {

                // If the i-th character of the string is equal to the (sz - j + 1)-th character of the string
                if(s[i - 1] == s[sz - j]) {

                    // Update dp[i][j] to be 1 plus the value of dp[i - 1][j - 1]
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {

                    // Otherwise, update dp[i][j] to be the maximum of dp[i - 1][j] and dp[i][j - 1]
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Return the value of dp[sz][sz], which represents the length of the longest palindromic subsequence
        return dp[sz][sz];
    }
};
