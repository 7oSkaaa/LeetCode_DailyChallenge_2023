// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the longest palindromic subsequence
    // we can use dp to solve this problem 
    // dp[i][j] = the longest palindromic subsequence between i and j
    // dp[i][j] = 1 if i == j

    // s: input string
    string s;
    // dp: memoization table
    int dp[1001][1001];

    // get_len: get the longest palindromic subsequence between i and j
    int get_len(int i, int j){
        // base case if i > j return 0
        if(i > j) return 0;
        // base case if i == j return 1
        if(i == j) return 1;

        // if we have already calculated the answer return it
        if(dp[i][j] != -1) return dp[i][j];

        // ans: the answer
        int ans = 0;

        // if the first and the last characters are equal then the answer is 2 + the answer between i + 1 and j - 1
        if(s[i] == s[j]) ans = max(ans, 2 + get_len(i + 1, j - 1));
        else{
            // if the first and the last characters are not equal then the answer is the maximum between
            // the answer between i + 1 and j and the answer between i and j - 1
            ans = max(ans, get_len(i + 1, j));
            ans = max(ans, get_len(i, j - 1));
        } 

        // return the answer
        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s) {
        // initialize the memoization table with -1
        memset(dp, -1, sizeof(dp));
        // set the input string
        this -> s = s;

        // return the answer
        return get_len(0, s.size() - 1);
    }
};
