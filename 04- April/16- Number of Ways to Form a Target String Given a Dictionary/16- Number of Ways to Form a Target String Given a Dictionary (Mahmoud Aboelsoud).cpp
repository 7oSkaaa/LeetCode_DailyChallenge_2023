// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the number of ways to form the target string from the given words
    // with the condition that if tool the i's letter some word then i can't take any letter with index less than or equal to i
    // so we can solve this problem by dp

    // freq: 2d array to store the frequency of each letter in each column
    vector<vector<int>> freq;
    // mod: the mod value
    int mod = 1e9 + 7;
    // dp: 2d array to store the number of ways to form the target string from the given words
    int dp[1001][1001];

    // target: the target string
    string target;

    // cnt_ways: function to count the number of ways to form the target string from the given words
    long long cnt_ways(int col, int idx){
        // if we reach the end of the target string then we can form the target string so we return 1
        if(idx == target.size()) return 1;
        // if we reach the end of the length of the words then we can't form the target string so we return 0
        if(col == freq.size()) return 0;

        // if we have already calculated the number of ways to form the target string from the given words
        if(dp[col][idx] != -1) return dp[col][idx];

        // we have two choices
        // 1- skip the current column
        long long ans = cnt_ways(col + 1, idx);

        // 2- take the current column and to count the number of ways to form the target
        // we need to multiply the number of words that have target[idx] in the current column by the number of ways to form the remaining target string
        ans += (freq[col][target[idx] - 'a'] * cnt_ways(col + 1, idx + 1)) % mod;
        ans %= mod;


        // return the number of ways to form the target string from the given words
        return dp[col][idx] = ans;
    }
    

    int numWays(vector<string>& words, string target) {
        // initialize the dp array with -1
        memset(dp, -1, sizeof(dp));
        // initialize the freq array
        freq.assign(words[0].size(), vector<int> (26, 0));
        // set the global target string
        this -> target = target;

        // count the frequency of each letter in each column
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                freq[j][words[i][j] - 'a']++;
            }
        }

        // return the number of ways to form the target string from the given words
        return cnt_ways(0, 0);
    }
};
