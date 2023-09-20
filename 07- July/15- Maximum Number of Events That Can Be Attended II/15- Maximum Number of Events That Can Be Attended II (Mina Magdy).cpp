// Author: Mina Magdy

class Solution {
public:
    int n, k; // Number of events and maximum events to attend
    vector<vector<int>> dp; // Dynamic programming table
    // Function to calculate the maximum value of events
    int max_value(vector<vector<int>>& events, int i = 0, int j = 0) {
        // Base case: If all events have been processed or we have attended maximum events, return 0
        if (i == n || j == k) {
            return 0;
        }
        int &ret = dp[i][j]; // Reference to the dynamic programming table value for current state
        // If value is already calculated, return it
        if (~ret)
            return ret;
        // Recursive case: Calculate the maximum value by either skipping the current event
        // or attending the current event and recursively calculating the maximum value for the remaining events
        ret = max_value(events, i + 1, j);
        vector<int> vc = {events[i][1] + 1, 0, 0}; // Create a vector to search for the next available event
        auto it = lower_bound(events.begin(), events.end(), vc); // Find the iterator pointing to the next available event
        // Update the maximum value by attending the current event and recursively calculating the maximum value
        // for the remaining events starting from the next available event
        return ret = max(ret, events[i][2] + max_value(events, it - events.begin(), j + 1));
    }
    // Function to find the maximum value of events
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size(); // Set the number of events
        this->k = k; // Set the maximum events to attend
        sort(events.begin(), events.end()); // Sort the events based on the start time
        dp = vector<vector<int>>(n, vector<int>(k, -1)); // Initialize the dynamic programming table with -1
        return max_value(events); // Call the max_value function to calculate the maximum value
    }
};
