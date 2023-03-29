// Author: Ahmed Gamal

// for this problem, we want to find the minimum cost to travel all the days
// we can use dp to solve this problem, but we need to find the recurrence relation
// dp[i]: the minimum cost to travel all the days from the day i to the last day
// dp[i] = min(dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + costs[2])
// the answer is dp[0]

// while we are solving the problem at day i, we can use binary search to find the index of the next day to travel in O(log(n))
// so the time complexity is O(nlog(n))

class Solution {
    // memo[i]: the minimum cost to travel all the days from the day i to the last day
    vector<int> memo;
public:
    int dp(int idx, vector<int>& days, vector<int>& costs) {
        // if we have traveled all the days, then the minimum cost is 0
        if(idx >= days.size()) {
            return 0;
        }

        // if we have already calculated the answer, then return it
        int& ret = memo[idx];
        if(~ret) {
            return ret;
        }

        // the minimum cost is 1e6 (infinity)
        ret = 1e6;

        // try to travel the next day, the next 7 days, and the next 30 days
        int d[] = {0, 6, 29};

        for(int i = 0; i < 3; i++) {
            // find the index of the next day to travel
            int nxt = upper_bound(days.begin(), days.end(), days[idx] + d[i]) - days.begin();

            // make the transition
            ret = min(ret, costs[i] + dp(nxt, days, costs));
        }

        return ret;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // initialize the memo array
        memo.assign(days.size() + 1, -1);

        // the answer is dp(0)
        return dp(0, days, costs);
    }
};