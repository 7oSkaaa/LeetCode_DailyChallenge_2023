/*
    We can do a basic dp aproach where:
        State: dp[i] = minimum extra characters in string s starting from index i
        Transition: dp[i] = min(delete s[i] , try all valid words that match a substring of s and the the one with minimum answer)
        Base Case: dp[s.size()] = 0 (empty string has 0 extra characters)
*/
class Solution
{
public:
    int dp[100];
    int helper(string &s, vector<string> &dict, int i)
    {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 1 + helper(s, dict, i + 1);

        for (auto &word : dict)
        {
            bool match = 1;
            for (int j = 0; j < word.size(); j++)
            {
                if (j + i >= s.size())
                    match = 0;
                else if (word[j] != s[j + i])
                    match = 0;
            }
            if (match)
                ans = min(ans, helper(s, dict, i + word.size()));
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string> &dict)
    {
        memset(dp, -1, sizeof(dp));
        return helper(s, dict, 0);
    }
};