// Author: Ahmed Hossam

class Solution {
public:
    // This function takes a vector of strings 'words' and a string 'target' as input and returns the number of ways to form the 'target' string
    int numWays(vector<string>& words, string target) {
        // Initializing variables
        int n = words.size(), len = words[0].size(), k = target.size();

        // Using a vector of unordered_map to store the frequency of each character in each position of the 'words' vector
        vector < unordered_map < char, int > > frequencies(len);
        
        // Calculating the frequency of each character in each position of the 'words' vector
        for(auto& word : words)
            for(int i = 0; i < len; i++)
                frequencies[i][word[i]]++;
        
        // Defining the constant MOD value
        constexpr int MOD = 1000000007;
        
        // Initializing a 2D vector 'dp' to store the number of ways to form the 'target' string
        vector < vector < int > > dp(k+1, vector < int > (len + 1));
        
        // Initializing the 'dp' vector for base case
        dp[0] = vector < int > (len + 1, 1);
        
        // Filling the 'dp' vector using dynamic programming
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= len; j++){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += (1ll * frequencies[j - 1][target[i - 1]] * dp[i - 1][j - 1]) % MOD;
                dp[i][j] %= MOD;
            }
        }

        // Returning the number of ways to form the 'target' string
        return dp[k][len];
    }

};
