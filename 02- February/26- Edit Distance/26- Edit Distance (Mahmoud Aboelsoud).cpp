// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum number of operations to convert s1 to s2
    // we can do that by using dp
    // at each step we have 3 options if the current characters are not equal
    // 1- insert a character in s1
    // 2- delete a character from s1
    // 3- replace a character in s1
    // we will take the minimum of these 3 options
    // if the current characters are equal we will just move to the next characters
    // we will use dp[i][j] to store the minimum number of operations to convert s1[0...i] to s2[0...j]

    // the memoization vector
    vector<vector<int>> dp;
    // the strings
    string s1, s2;

    // the function to calculate the minimum number of operations
    int min_dist(int i, int j){
        // if we reached the end of one of the strings we will return the number of remaining characters in the other string
        if(i == s1.size() || j == s2.size()) return s1.size() - i + s2.size() - j;
        // if we have already calculated the answer we will return it
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        // if the current characters are equal we will move to the next characters without any operation 
        if(s1[i] == s2[j])
            ans = min(ans, min_dist(i + 1, j + 1));
        else{
            // if the current characters are not equal we will try all 3 options

            // insert a character in s1
            ans = min(ans, 1 + min_dist(i, j + 1));
            // delete a character from s1
            ans = min(ans, 1 + min_dist(i + 1, j));
            // replace a character in s1
            ans = min(ans, 1 + min_dist(i + 1, j + 1));
        }

        // store the answer and return it
        return dp[i][j] = ans;
    }


    int minDistance(string word1, string word2) {
        // initialize the strings and the memoization vector
        s1 = word1, s2 = word2;
        dp.assign(s1.size() + 1, vector<int> (s2.size() + 1, -1));
        
        // return the answer
        return min_dist(0, 0);
    }
};
