//Author: Abdelrrahman Elhaddad


class Solution {
private:
const int oo = 0x3f3f3f3f; // Our maximum value
int dp[366][1000]; // To store nodes values based on the day and the remaining days I am able to travel on (Memoization)
int n;

public:
int rec(int i, int remainingDays, int preI, vector<int> &days, vector<int> &costs) {
    if (i == n) // If finished all the planned days then return 0
        return 0;

    int &ans = dp[i][remainingDays];
    if (~ans) // If ans != -1 that means I have visited before then return it
        return ans;
    ans = oo; // If not, set it to maximum
    
    remainingDays -= (days[i] - days[preI]); // Subtracting the days between the previous day and current day to check whether I have valid pass

    if (remainingDays <= 0) { // If I am out of available trips
        ans = min(ans, costs[0] + rec(i + 1, 1, i, days, costs)); // Buy a 1-day pass 
        ans = min(ans, costs[1] + rec(i + 1, 7, i, days, costs)); // buy a 7-day pass 
        ans = min(ans, costs[2] + rec(i + 1, 30, i, days, costs)); // buy a 30-day pass 
    } else
        ans = min(ans, rec(i + 1, remainingDays, i, days, costs)); // If I still have available trips (There is no need for buying a pass)

    return ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs) {
    n = days.size();
    memset(dp, -1, sizeof dp); // Filling dp array with -1
    return rec(0, 0, 0, days, costs);
}
};
