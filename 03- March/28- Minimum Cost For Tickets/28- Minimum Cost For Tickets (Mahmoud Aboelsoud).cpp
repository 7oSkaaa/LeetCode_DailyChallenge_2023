// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum cost to travel all days
    // so at each day we have 3 options
    // 1- buy a 1 day ticket
    // 2- buy a 7 day ticket
    // 3- buy a 30 day ticket
    // so we will try all 3 options and choose the minimum cost
    // we will use dp to store the minimum cost for each day

    // dp array
    int dp[400];
    // days and costs arrays that we will get from the input
    vector<int> days, costs;

    // function to get the minimum cost for a given day
    int get_min(int idx){
        // if we reached the end of the days array then we have traveled all days then return 0
        if(idx == days.size()) return 0;
        // if we have already calculated the minimum cost for this day then return it
        if(dp[idx] != -1) return dp[idx];

        // try all 3 options and choose the minimum cost
        int ans = costs[0] + get_min(idx + 1);

        int u = upper_bound(days.begin(), days.end(), days[idx] + 7 - 1) - days.begin();
        ans = min(ans, costs[1] + get_min(u));

        u = upper_bound(days.begin(), days.end(), days[idx] + 30 - 1) - days.begin();
        ans = min(ans, costs[2] + get_min(u));

        // store the minimum cost for this day and return it
        return dp[idx] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // store the days and costs arrays
        this -> days = days, this -> costs = costs;
        // initialize the dp array with -1
        memset(dp, -1, sizeof(dp));

        // return the minimum cost for the first day
        return get_min(0);
    }
};
