// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        //dp[i][j] = cost to reach jth city using atmost i edges from src
        //cost to reach srv always will be 0
        for(int i=0;i<=k+1;i++){
            dp[i][src]=0;
        }
        // try all number of edges
        for(int i=1;i<=k+1;i++){
            for(auto flight:flights){
                // if(from city) have been visited using i-1 edges
                if(dp[i-1][flight[0]]!=INT_MAX){
                    // update (to city) using i edges
                    dp[i][flight[1]]=min(dp[i][flight[1]],dp[i-1][flight[0]]+flight[2]);
                }
            }
        }
        // if dst city have been visited using atmost k+1 edges then return the cost
        // if it equal INT_MAX then it unvisited so return -1
        return (dp[k+1][dst]==INT_MAX?-1:dp[k+1][dst]);
    }
};