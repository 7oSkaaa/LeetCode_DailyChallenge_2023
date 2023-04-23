// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum number of insertions to make the string palindrome
    // so we can use dp to solve this problem
    // at each step we have three options
    // 1- if the first and last characters are equal we can ignore them and move to the next step
    // 2- if the first and last characters are not equal we can insert the first character at the end
    // 3- if the first and last characters are not equal we can insert the last character at the beginning

    // dp : memoization table
    int dp[501][501];
    // s : the input string
    string s;
    
    // cnt : the function that returns the minimum number of insertions to make the string palindrome
    int cnt(int i, int j){
        // if the beginning index is greater than or equal to the ending index we have reached the end of the string
        // so we return 0
        if(i >= j) return 0;

        // if the current state is already calculated we return the answer
        if(dp[i][j] != -1) return dp[i][j];

        // ans: the minimum number of insertions to make the string palindrome from i to j
        int ans = INT_MAX;
        // if the first and last characters are equal we can ignore them and move to the next step
        if(s[i] == s[j]) ans = cnt(i + 1, j - 1);
        else{
            // if the first and last characters are not equal we take the minimum of two options
            // 1- we can insert the first character at the end
            ans = min(ans, 1 + cnt(i + 1, j));
            // 2- we can insert the last character at the beginning
            ans = min(ans, 1 + cnt(i, j - 1));
        }

        // return the answer and store it in the memoization table
        return dp[i][j] = ans;
    }

    int minInsertions(string s) {
        // set the input string
        this -> s = s;
        // initialize the memoization table with -1
        memset(dp, -1, sizeof(dp));

        // return the answer of the problem from the first character to the last character
        return cnt(0, s.size() - 1);
    }
};
