// Author: Mina Magdy

class Solution {
public:
    // Function to find the maximum number of requests that can be processed
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // Initialize the maximum number of requests to 0
        int ans = 0;
        // Get the total number of requests
        int m = requests.size();
        // Iterate over all possible subsets of requests using bit manipulation
        for (int i = 0; i < (1 << m); i++) {
            // Create an array to track the net change for each computer
            vector<int> net(n);
            // Process the requests in the current subset
            for (int j = 0; j < m; j++) {
                // Check if the j-th request is included in the current subset
                if ((i >> j) & 1) {
                    // Get the j-th request
                    auto &req = requests[j];
                    // Decrease the count for the source computer
                    net[req[0]]--;
                    // Increase the count for the destination computer
                    net[req[1]]++;
                }
            }
            // Check if all computers have a net change of 0 (balanced)
            if (!count_if(net.begin(), net.end(), [&](int &a){ return a != 0; }))
                // Update the maximum number of requests
                ans = max(ans, __builtin_popcount(i));
        }
        // Return the maximum number of requests that can be processed
        return ans;
    }
};
