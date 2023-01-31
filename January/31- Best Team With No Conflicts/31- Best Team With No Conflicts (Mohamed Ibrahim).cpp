//Author: Mohamed Ibrahim

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> vc(n);
        for(int i=0;i<n;i++)
            vc[i] = {ages[i],scores[i]}; // Store the ages and scores as pairs in vc vector
        sort(vc.begin(),vc.end()); // Sort it
        return highestScore(n,vc); // Call highestScore function and return its result
    }

    int highestScore(int n, vector<pair<int,int>> &vc){
        int mx = 0; // Initialize mx to 0
        vector<int> dp(n); // Declare a vector dp with size n
        for(int i=0;i<n;i++){
            dp[i] = vc[i].second; // Set dp[i] to the score of the corresponding pair in vc
            for(int j = i-1;j>=0;j--) // Inner loop starting from previous index of i and going till 0
                if(vc[i].second >= vc[j].second)
                    dp[i] = max(dp[i],dp[j]+vc[i].second); // If score of current pair is >= score of previous pair, update dp[i] to be the max of its previous value and dp[j]+vc[i].second
            mx = max(mx,dp[i]); // Update mx to be the max of its previous value and dp[i]
        }
        return mx; // Return the final value of mx
    }
};
