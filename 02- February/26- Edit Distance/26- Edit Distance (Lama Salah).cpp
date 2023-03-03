// Author: Lama Salah

class Solution {
    int n,m, memo[505][505];
    string s, t;

public:

    int dp (int i, int j){
        if (j == m) return n-i; // Delete all remain characters in string s
        if (i == n) return m-j; // Insert all remain characters in string t to string s

        int& ans = memo[i][j];
        if (~ans) return ans;

        if (s[i] == t[j]) ans = dp(i+1, j+1);
        else {
            ans = 1 + dp(i+1, j); // Delete
            ans = min(ans, 1 + dp(i, j+1)); // Insert
            ans = min(ans, 1 + dp(i+1, j+1)); // Replace
        }

        return ans;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        s = word1, t = word2;

        for (int i = 0; i < n + 5; i++)
            for (int j = 0; j < m + 5; j++) 
                memo[i][j] = -1;

        return dp(0, 0);
    }
};