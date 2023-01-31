// Author: Ahmed Hossam

class Solution {
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // number of players and maxAge of the players to initial the dp vectors
        int n = scores.size(), maxAge = *max_element(ages.begin(), ages.end());

        // make vector of pairs the first is the score and the second is the age to sort it
        vector < pair < int, int > > players(n);
        for(int i = 0; i < n; i++)
            players[i] = {scores[i], ages[i]};
        sort(players.begin(), players.end());

        // make dp state with rolling back
        vector < vector < int > > dp(2, vector < int > (maxAge + 5));
        
        for(int i = n - 1; i >= 0; i--){
            // if we will skip this players so the answer will the same for the previous player
            dp[i % 2] = dp[(i + 1) % 2];

            // we want for each age in the range between [1, age of the i-th player] to calculate the max of take it or leave it
            for(int age = 1; age <= players[i].second; age++)
                dp[i % 2][age] = max(dp[i % 2][age], players[i].first + dp[(i + 1) % 2][players[i].second]);
        }

        // return the max state for the first player
        return *max_element(dp[0].begin(), dp[0].end());
    }
};
