// Author: Mohamed Emara

class Solution {
public:
    int dp[1005][1005];
    string str;
    int n;
    int rec(int l, int r)
    {
        // base case
        if(l > r)       // zero as it's an invalid case
            return 0;
        if(l == r)      // As the inner most element is palindrome with itself 
            return 1;

        // memoization
        int &ret = dp[l][r];
        if(~ret)
            return ret;
        
        // transition
        if(str[l] == str[r])
        {
            ret = 2 + rec(l+1, r-1);
        }
        else 
        {
            ret = max(rec(l+1, r), rec(l, r-1));
        }
        return ret;
    }

    int longestPalindromeSubseq(string s) {
        // ====== IDEA ====== //
        /*
            starting from the farthest two ends, 
            if the left character is the same as the right one
                - it's better to take them both to the result string
                - & check what from the inners characters will be palindrome
            if they're not the same
                - try to take the right one and skip the left one
                - and to take the left one and skip the right one
                - maximize between them to see what is the maximum final result
        */
        
        // fill global variables 
        str = s;
        n = s.length();
   
        // initialize the memoization array with -1 to know whether it's visited or not
        memset(dp, -1, sizeof(dp));
        return rec(0, n-1);
    }
};

