// Author: Ahmed Gamal

// for this problem, we need to find the minimum number of insertions to make the string a palindrome
// we can use dp to solve it
// we have 2 cases:
// 1- if the first and last characters are equal, then we can ignore them and solve the problem for the rest of the string
// 2- if the first and last characters are not equal, then we can either insert the first character at the end of the string, or insert the last character at the beginning of the string
// we can use a 2d dp array to store the answer for each substring
// the answer for the substring from l to r is the minimum number of insertions to make the substring a palindrome


class Solution {
    // N: maximum length of the string
    // memo: dp array
    // s: the string
    static const int N = 501;
    int memo[N][N];
    string s;

    // dp(l, r): minimum number of insertions to make the substring from l to r a palindrome
    int dp(int l, int r) {
        // base case
        if(l >= r) {
            return 0;
        }

        // if we have already calculated the answer, then return it
        int& ret = memo[l][r];
        if(~ret) {
            return ret;
        }

        // if the first and last characters are equal, then we can ignore them and solve the problem for the rest of the string
        ret = 0;
        if(s[l] == s[r]) {
            ret = dp(l + 1, r - 1);
        } else {
            // if the first and last characters are not equal, then we can either insert the first character at the end of the string, or insert the last character at the beginning of the string
            ret = 1 + min(dp(l + 1, r), dp(l, r - 1));
        }

        // return the answer
        return ret;
    }

public:
    int minInsertions(string s) {
        // initialize the variables
        memset(memo, -1, sizeof memo);
        this -> s = s;
        
        // return the answer
        return dp(0, s.size() - 1);
    }
};