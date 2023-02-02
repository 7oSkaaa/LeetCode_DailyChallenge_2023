// author: Esraa Syam
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector < pair < int, int > > v;
        int n = scores.size();
        for(int i = 0; i < n; i++){
            v.push_back({ages[i], scores[i]});
        }
        // sort by age 
        sort(v.begin(), v.end());
        // use dp to find the max score of a valid team 
        vector < int > dp(n, 0);
        // iterate over all players
        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
            // iterate over all previous players of the current player so that we can find the max score of a valid team
            for(int j = 0; j < i; j++){
                // if the current player who older than the previous player his score is greater than or equal to the previous player's score
                // then we can add him (the previous) to the team (the current)
                if(v[j].second <= v[i].second){
                    // update the max score of a valid team
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }
        }
        // return the max score of a valid team 
        return *max_element(dp.begin(), dp.end());
    }
};