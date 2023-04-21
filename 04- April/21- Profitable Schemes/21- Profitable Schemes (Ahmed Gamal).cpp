// Author: Ahmed Gamal

// for this problem, we can use dp to solve it as it is a knapsack problem
// for each crime, we can either include it or not include it
// if we include it, then we can only include it if we have enough members available and we can only increase the profit by the profit of the crime
// if we don't include it, then we don't need to change the number of members available, nor the profit
// we can use a 3d dp array to store the answer for each crime, the number of members available, and the profit
// as we are caring about the schemes with at least minProfit, we can use a min function to update the profit to make sure that it is at least minProfit


class Solution {
    // MOD: big prime number
    // N: maximum number of crimes
    // memo: dp array
    // group: number of members required for each crime
    // profit: profit of each crime
    // n: number of members available
    // minProfit: minimum profit required

    static const int MOD = 1000000007, N = 101;
    int memo[N][N][N];
    vector<int> group, profit;
    int n, minProfit;

    // dp(idx, mem, p): number of schemes with at least minProfit profit, if we have mem members available, and we have considered the crimes from idx to the end
    int dp(int idx, int mem, int p) {
        // base case
        if(idx >= group.size()) {
            return p >= minProfit;
        }

        // if we have already calculated the answer, then return it
        int& ret = memo[idx][mem][p];
        if(~ret) {
            return ret;
        }

        // if we don't include the current crime, then we don't need to change the number of members available, nor the profit
        ret = dp(idx + 1, mem, p);

        // if we include the current crime, then we can only include it if we have enough members available and we can only increase the profit by the profit of the crime
        if(mem >= group[idx]) {
            ret += dp(idx + 1, mem - group[idx], min(minProfit, p + profit[idx]));
        }
        // make sure that the answer is in the range [0, MOD)
        ret %= MOD;

        return ret;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // initialize the variables
        this -> group = group;
        this -> n = n;
        this -> profit = profit;
        this -> minProfit = minProfit;

        // initialize the dp array
        memset(memo, -1, sizeof memo);

        // call the function recursively
        return dp(0, n, 0);
    }
};