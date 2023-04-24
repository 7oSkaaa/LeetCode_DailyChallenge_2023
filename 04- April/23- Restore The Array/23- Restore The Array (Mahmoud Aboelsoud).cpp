// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to count the number of ways to split the string into numbers <= k and doesn't start with 0
    // we can use dp to solve this problem
    // dp[i] = number of ways to split the string starting from index i

    // s: input string
    // k: maximum value of the numbers
    string s;
    int dp[100005], k, mod = 1e9 + 7;

    // cnt_ways(idx) = number of ways to split the string starting from index idx
    int cnt_ways(int idx){
        // base case if we reach the end of the string we return 1
        if(idx == s.size()) return 1;

        // if the string starts with 0 we return 0
        if(s[idx] == '0') return 0;

        // if we already calculated the number of ways to split the string starting from index idx we return it
        if(dp[idx] != -1) return dp[idx];
        
        // ans: number of ways to split the string starting from index idx
        // x: the number we are currently trying to split the string from
        int ans = 0;
        long long x = 0;
        // we try to split the string starting from index idx to all possible numbers
        for(int i = idx; i < s.size(); i++){
            // we add the current digit to the number we are trying to split the string from
            x = x * 10 + (s[i] - '0');
            // if the number is greater than k we break
            if(x <= k){
                // we add the number of ways to split the string starting from index i + 1 to the answer
                ans += cnt_ways(i + 1);
                ans %= mod;
            }else break;
        }

        // we return the answer
        return dp[idx] = ans;
    }


    int numberOfArrays(string s, int k) {
        // we initialize the string and k
        this -> s = s;
        this -> k = k;
        // we initialize the dp array with -1
        memset(dp, -1, sizeof(dp));

        // we return the number of ways to split the string starting from index 0
        return cnt_ways(0);
    }
};
