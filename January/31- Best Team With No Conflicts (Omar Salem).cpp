//Author:Omar Salem
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
         // initialize the vector
        vector < pair < int , int > > v;
        for(int i = 0 ; i < scores.size() ;i++)
            v.push_back({ages[i] , scores[i]});
        /*
        1 1 2 2
        5 5 4 6
        */
        sort(v.begin() , v.end());// Sort by ages 
         // initialize dp vector
        vector < int > dp(scores.size()) ; 
        int ans = 0 ;
       
        for(int i = 0; i < scores.size(); i++) {
            dp[i] = v[i].second;
            for(int j = 0; j < i; j++) {
            // check if the current player score is greater than or equal to the previous player
                if(v[j].second <= v[i].second)
                    dp[i] = max(dp[i], dp[j] + v[i].second);
            }
            ans = max(ans, dp[i]);
            //0 1 2 3 
            //5 10  16 
        }
        return ans ;
    }
};