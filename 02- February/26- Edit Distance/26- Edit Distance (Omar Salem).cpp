// Author : Omar Salem
class Solution {
public:
    int DP(int i , int j , string& s1 , string& s2 ,vector<vector<int>>&dp)
    {
        // if word1 is empty
        if(i < 0 )
            return j+1;
        // if word1 is empty
        if(j < 0 )
            return i+1;
        // if both char is a same 
        if(s1[i] == s2[j])
            return DP(i-1, j-1 ,s1, s2 , dp);
        // if dp[i][j] != -1 then we found solution 
        // no need to recursion again and return ans
        if(dp[i][j] != -1)
            return dp[i][j];

        // to delete char
        int min1 = DP(i-1 , j , s1, s2,dp);
        // to insert char
        int min2 = DP(i , j-1 , s1, s2,dp);
        // to replace char
        int min3 = DP(i-1 , j-1 , s1, s2,dp);

        return dp[i][j] = 1 + min({min1, min2 , min3});
    }


    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector< int > > dp(n , vector< int > (m ,-1));
        return DP(n-1, m-1 , word1, word2 ,dp);
    }
};


