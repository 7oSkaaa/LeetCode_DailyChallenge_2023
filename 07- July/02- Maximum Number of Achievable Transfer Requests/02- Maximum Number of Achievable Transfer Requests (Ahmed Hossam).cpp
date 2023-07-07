// Author: Ahmed Hossam

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // Initialize variables r and maxReq.
        int r = requests.size(), maxReq = 0;
        
        // Iterate through all possible combinations of requests using a bitmask.
        for(int mask = 0; mask < (1 << r); mask++){
            // Create a vector net to keep track of the degree of each node.
            vector < int > net(n);
            
            // Iterate through each request in the requests vector.
            for(int i = 0; i < r; i++){
                // Check if the i-th request is included in the bitmask.
                if(mask & (1 << i)){
                    // If the request is included, decrement the net of the source node
                    // and increment the net of the destination node.
                    net[requests[i][0]]--;
                    net[requests[i][1]]++;
                }
            }
            
            // Check if all nodes have a net of 0, indicating that requests can be made.
            bool can_make_requests = true;
            for(int i = 0; i < n; i++)
                can_make_requests &= (net[i] == 0);
            
            // If all nodes have a net of 0, update maxReq with the maximum number of requests made.
            if(can_make_requests)
                maxReq = max(maxReq, __builtin_popcount(mask));
        }
        
        // Return the maximum number of requests that can be made.
        return maxReq;
    }
};
