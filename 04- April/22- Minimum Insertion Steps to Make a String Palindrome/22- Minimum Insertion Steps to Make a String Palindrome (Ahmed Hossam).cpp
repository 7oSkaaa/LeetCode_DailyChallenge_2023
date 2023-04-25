// Author: Ahmed Hossam

class Solution {
public:
    // This function calculates the minimum number of insertions needed to make a given string a palindrome.
    int minInsertions(const string& s) {

        // The size of the string.
        int n = s.size();

        // Creating a 2D vector of size 2 x (n+1) to store the dynamic programming table.
        vector < vector < int > > dp(2, vector < int > (n + 1));

        // Looping through the string from end to start.
        for(int l = n; l >= 1; l--) {

            // Looping through the string from start to end.
            for(int r = l; r <= n; r++) {

                // If the characters at the left and right ends are same, then the answer is the same as that for the substring without these two characters.
                if(s[l - 1] == s[r - 1]) 
                    dp[l & 1][r] = dp[(l + 1) & 1][r - 1];

                // Else, we need to add one character either at the beginning or end, so we take the minimum of two cases:
                // 1) Add character to the left end and recur for substring s[l+1..r]
                // 2) Add character to the right end and recur for substring s[l..r-1]
                else
                    dp[l & 1][r] = 1 + min(dp[(l + 1) & 1][r], dp[l & 1][r - 1]);
            }
        }

        // Returning the answer, which is stored in dp[1][n].
        return dp[1][n];
    }

};
