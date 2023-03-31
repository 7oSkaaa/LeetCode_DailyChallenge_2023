// Author: Mina Magdy

class Solution {
public:
    vector<int> dp;  // Declare an array to store the minimum cost for each day.
    Solution() {
        dp.assign(370, -1);  // Initialize the array with -1 for all the days from 0 to 369.
    }
    int mincostTickets(vector<int>& days, vector<int>& costs, int idx = 0) {
        if (idx == days.size()) return 0;  // If all the days have been processed, return 0.
        int &ret = dp[idx];  // Get the reference to the minimum cost for the current day.
        if (~ret) return ret;  // If the minimum cost for the current day has already been calculated, return it.
        ret = 1e9;  // Initialize the minimum cost for the current day as a very large number.
        ret = min(ret, costs[0] + mincostTickets(days, costs, lower_bound(days.begin(), days.end(), days[idx] + 1) - days.begin()));  // Calculate the minimum cost for the current day if a 1-day pass is used.
        ret = min(ret, costs[1] + mincostTickets(days, costs, lower_bound(days.begin(), days.end(), days[idx] + 7) - days.begin()));  // Calculate the minimum cost for the current day if a 7-day pass is used.
        ret = min(ret, costs[2] + mincostTickets(days, costs, lower_bound(days.begin(), days.end(), days[idx] + 30) - days.begin()));  // Calculate the minimum cost for the current day if a 30-day pass is used.
        return ret;  // Return the minimum cost for the current day.
    }
};
