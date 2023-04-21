// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the number of ways to choose a subset of the projects such that the total number of members that are involved in that subset is at most n, and the total profit is at least minProfit.
    // we can use dp to solve this problem
    // our dp will be 3d dp
    // we will stroe 3 states
    // 1- the index of the current project
    // 2- the number of members that are involved in the current subset
    // 3- the total profit of the current subset

    // n: the number of members
    // minProfit: the minimum profit
    // group: the number of members that are involved in each project
    // profit: the profit of each project 
    int n, minProfit, mod = 1e9 + 7;
    vector<int> group, profit;  
    int dp[101][101][102];
    

    // cnt_ways(idx, num, tot) will return the number of ways to choose a subset of the projects such that the total number of members that are involved in that subset is at most num, and the total profit is at least tot.
    int cnt_ways(int idx, int num, int tot){
        // when we reach the end of the projects
        if(idx == group.size()){
            // we check if the total profit is at least minProfit if so we return 1 else we return 0
            if(tot >= minProfit) return 1;
            return 0;
        }

        // if we have already calculated the number of ways to choose a subset of the projects such that the total number of members that are involved in that subset is at most num, and the total profit is at least tot.
        if(dp[idx][num][tot] != -1) return dp[idx][num][tot];

        // we have 2 choices
        // 1- skip the current project
        long long ans = cnt_ways(idx + 1, num, tot);
        ans %= mod;

        // 2- include the current project if if the number of members int the current project + num <= n
        if(group[idx] + num <= n) 
            ans += cnt_ways(idx + 1, group[idx] + num, min(101, tot + profit[idx])); 
        ans %= mod;

        // we return the number of ways to choose a subset of the projects such that the total number of members that are involved in that subset is at most num, and the total profit is at least tot.
        return dp[idx][num][tot] = ans;
    }



    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // we set the global variables to the input variables
        this -> n = n, this -> minProfit = minProfit, this -> group = group, this -> profit = profit;
        // we initialize the dp with -1
        memset(dp, -1, sizeof(dp));

        // call cnt_ways starting from the first project, the number of members that are involved in the current subset is 0, and the total profit of the current subset is 0
        return cnt_ways(0, 0, 0);
    }
};
