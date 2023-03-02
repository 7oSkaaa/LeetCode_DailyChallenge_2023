// author : Ahmed Zedan
class Solution {
public:
    vector<vector<int>>dp ; // memozation
    string s1 , s2 ; 
    int n , m ; 
    // recursive dp 
    int rec(int i=0 , int j=0){
        if(i==n) return m-j ; // inert remain char in s2 to s1
        if(j==m) return n-i ; // delete remain char in s1 
        int &ret = dp[i][j] ; 
        if(~ret) return ret ; 
        if(s1[i]==s2[j]) return ret = rec(i+1,j+1) ; 
        return ret = 1 + min({rec(i+1,j+1),rec(i+1,j),rec(i,j+1)}) ; 
        /*
            to replace call rec(i+1,j+1) 
            to insert call  rec(i,j+1)
            to delete call  rec(i+1,j)
        */
    }
    int minDistance(string word1, string word2) {
        s1 = word1 ; 
        s2 = word2 ; 
        n = s1.size() ;
        m = s2.size() ; 
        dp = vector<vector<int>>(n,vector<int>(m,-1)) ; 
        return rec() ; 
    }
};