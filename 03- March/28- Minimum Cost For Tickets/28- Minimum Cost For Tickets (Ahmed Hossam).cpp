// Author: Ahmed Hossam

class Solution {
public:
    // A function that takes in a vector of days and a vector of costs and returns the minimum cost of tickets.
    int mincostTickets(vector < int >& days, vector < int >& costs) {
        // n is the size of the days vector.
        int n = days.size();
        
        // dp is a vector of size n+5 initialized to 0, where dp[i] represents the minimum cost of tickets starting from day i.
        vector < int > dp(n + 5, 0);
        
        // Starting from the end of the days vector, iterate through each day backwards.
        for(int idx = n - 1; idx >= 0; idx--){
            
            // tempidx is a variable to store the index of the day after the current day that needs to be covered by the ticket.
            int tempidx = -1;

            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 1 day.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 1) - days.begin();
            
            // Calculate the cost of the ticket that covers only one day, and add the cost to the minimum cost starting from tempidx.
            int first = costs[0] + dp[tempidx];
            
            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 7 days.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 7) - days.begin();
            
            // Calculate the cost of the ticket that covers 7 days, and add the cost to the minimum cost starting from tempidx.
            int second = costs[1] + dp[tempidx];
            
            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 30 days.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 30) - days.begin();
            
            // Calculate the cost of the ticket that covers 30 days, and add the cost to the minimum cost starting from tempidx.
            int third = costs[2] + dp[tempidx];
            
            // Store the minimum cost among the three options in dp[idx], which represents the minimum cost starting from day idx.
            dp[idx] = min(first, min(second, third)); 
        }

        // Return the minimum cost starting from day 0, which is stored in dp[0].
        return dp[0];
    }
};
