// Author: Ahmed Hossam

class Solution {
public:

    int n;  // Number of events
    vector<vector<int>> dp;  // Dynamic programming table to store computed results
 
    // Function to get the index of the next event
    // Returns the index of the next event after the current event
    int get_next_event(int idx, vector<vector<int>>& events){
        int l = idx + 1, r = n - 1, ans = n;
        while(l <= r){
            int m = l + (r - l) / 2;
            (events[m][0] > events[idx][1] ? r = m - 1, ans = m : l = m + 1);
        }
        return ans;
    }

    // Function to compute the maximum sum of event values
    int maxSum(int idx, int events_left, vector<vector<int>>& events){
        if(idx == n) return 0;  // Base case: No more events left to consider
        int& ret = dp[idx][events_left];
        if(~ret) return ret;  // If result is already computed, return it
        ret = maxSum(idx + 1, events_left, events);  // Exclude the current event
        if(events_left){
            int next_idx = get_next_event(idx, events);
            // Include the current event and recursively compute the maximum sum
            ret = max(ret, maxSum(next_idx, events_left - 1, events) + events[idx][2]);
        }
        return ret;
    }

    // Function to calculate the maximum value of events that can be attended
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();  // Number of events
        sort(events.begin(), events.end());  // Sort events based on their starting time
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));  // Initialize the DP table
        return maxSum(0, k, events);  // Compute and return the maximum sum
    }
};
