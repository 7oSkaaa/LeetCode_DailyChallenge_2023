// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // save the age ans score of each player
        // age as first and score as second to sort them according to thier ages
        vector<pair<int,int>>v;
        int ans=0;
        // dp vector to memorize the sum of scores to the team that started from player 0 to the ith player
        vector<int>dp(ages.size());
        for(int i=0;i<ages.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        // sort players in the descending order 
        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<ages.size();i++){
            dp[i]=v[i].second;
            for(int j=0;j<i;j++){
                // if the score of the jth player is greater than or equal to ith player (to avoid conflict )
                if(v[j].second>=v[i].second){
                    // then add ith player to the team
                    dp[i]=max(dp[i],dp[j]+v[i].second);
                }
            }
            // update ans
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};