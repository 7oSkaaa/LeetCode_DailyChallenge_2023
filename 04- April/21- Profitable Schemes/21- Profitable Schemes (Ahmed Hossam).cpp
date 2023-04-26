// Author: Ahmed Hossam

class Solution {
public:

    // Constants
    static constexpr int MOD = 1e9 + 7;
    static constexpr int N = 105;

    // Declare variables
    int dp[N][N][N];
    int n, minProfit;
    vector < int > group, profit;

    // Function to count the number of ways to form profitable schemes
    int cnt_ways(int idx, int members, int prof){
        // If we have iterated through all the groups, check if the profit is greater than or equal to minProfit
        if(idx == group.size()) return prof >= minProfit;
        
        // Memoization
        int& ret = dp[idx][members][prof];
        if(~ret) return ret;
        
        // Recursion
        ret = cnt_ways(idx + 1, members, prof) % MOD;
        if(members + group[idx] <= n)
            ret = (ret + cnt_ways(idx + 1, members + group[idx], min(minProfit, prof + profit[idx]))) % MOD;
        return ret;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Initialize variables
        memset(dp, -1, sizeof(dp));
        this -> group = group, this -> profit = profit;
        this -> n = n, this -> minProfit = minProfit;
        
        // Call recursive function and return result
        return cnt_ways(0, 0, 0);
    }

};
