// Author: Ahmed Gamal

// for this problem, we can use DP to solve it
// since we not using any character in an index before the chosen character in a string, we can visualize the dictionary as an array of frequencies of each character in each index
// for example, if the dictionary is {"abc", "abd", "acd"}, then the array of frequencies will be:
// 3 0 0 0 0 0 .. 0 
// 0 2 1 0 0 0 .. 0
// 0 1 1 1 0 0 .. 0

// now, we can see that in each row of the array, we can choose the character we want to with frequency ways
// for example, if we want to choose the character 'a' in the first row, we can do it in 3 ways
// if we want to choose the character 'b' in the second row, we can do it in 2 ways
// if we want to choose the character 'c' in the third row, we can do it in 1 way
// and so on

// now, we can use DP to solve the problem
// dp[i][j] = number of ways to create the string target[j..] using the rows[i..] of the array of frequencies
// dp[i][j] = dp[i + 1][j] + (if j < target.size()) freq[i][target[j] - 'a'] * dp[i + 1][j + 1]


class Solution {
    // MOD = 1e9 + 7
    // n = number of rows in the array of frequencies
    // memo = memoization table
    // freq[i][j] = number of times the character 'a' + j appears in the row i of the array of frequencies
    const int MOD = int(1e9) + 7;
    int n;
    vector<vector<long long>> memo; 
    vector<vector<int>> freq;
    
    // add b to a, and take the modulo of the result by MOD
    void add(long long& a, long long b) {
        a = (a += b) % MOD;
    }
    
    // dp(i, j) = number of ways to create the string target[j..] using the rows[i..] of the array of frequencies
    long long dp(int idx, int curr, string& target) {
        // if we reached the end of the target string, then we can create it using the remaining rows of the array of frequencies
        if(idx >= n) {
            return curr == target.size();
        }

        // if the current state is already calculated, return the result
        long long& ret = memo[idx][curr];
        if(~ret) {
            return ret;
        }

        // dp(i, j) = dp(i + 1, j) + (if j < target.size()) freq[i][target[j] - 'a'] * dp(i + 1, j + 1)
        ret = dp(idx + 1, curr, target);
        if(curr < target.size()) {
            add(ret, 1ll * freq[idx][target[curr] - 'a'] * dp(idx + 1, curr + 1, target));
        }

        return ret;
    }
public:
    int numWays(vector<string>& words, string target) {
        // initialize your variables
        n = (int)words[0].size();
        memo.assign(n + 5, vector<long long>(target.size() + 5, -1));
        freq.assign(n + 5, vector<int>(26));

        // calculate the array of frequencies
        for(auto& word : words) {
            for(int c = 0; c < word.size(); c++) {
                freq[c][word[c] - 'a']++;
            }
        }

        // return the answer
        return dp(0, 0, target);
    }
};