// Author: Mahmoud Aboelsoud

class Solution {
public:    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // our goal is to find the maximum sum of scores of increasing ages subsequence
        // so we sort the ages and try to find the maximum sum of scores of increasing ages subsequence
        // we use somthing like LIS so at each index we try to attach it to the end of the previous increasing ages subsequence with the maximum sum of scores
        // with respect to the condition of that younger players have to have a score less than or equal to the score of the older players
        // so we try to find the maximum sum of scores of increasing ages subsequence with the condition that the score of the current player is greater than or equal to the score of the previous player
        // using dp
        // dp[i] = maximum sum of scores of increasing ages subsequence ending at index i


        // number of players
        int n = scores.size();
        // vector of pairs of ages and scores
        vector<pair<int,int>> v;
        // initialize the vector
        v.assign(n, {0, 0});

        // fill the vector
        for(int i = 0; i < n; i++)
            v[i] = {ages[i], scores[i]};

        // sort the vector by the ages
        sort(v.begin(), v.end());


        // intialize variable to store the answer
        int ans = 0;
        // initialize dp vector
        vector<int> dp(n + 5, 0);


        // loop over the players
        for(int i = 0; i < n; i++){
            // the bst variable will store the maximum sum of scores of increasing ages subsequence ending at index i
            dp[i] = v[i].second;
            // loop over the previous players
            // we try to attach the current player to the end of the previous increasing ages subsequence with the maximum sum of scores
            for(int j = i - 1; j >= 0; j--){
                // check if the current player score is greater than or equal to the previous player
                if(v[i].second >= v[j].second)
                    // update the maximum sum of scores of increasing ages subsequence ending at index i
                    dp[i] = max(dp[i], v[i].second + dp[j]);
            }
            // update the answer
            ans = max(ans, dp[i]);
        }

        // return the answer
        return ans;
    }
};
