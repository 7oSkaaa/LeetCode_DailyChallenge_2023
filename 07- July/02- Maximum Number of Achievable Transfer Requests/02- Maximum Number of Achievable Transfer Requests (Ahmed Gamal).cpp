// Author: Ahmed Gamal

// for this problem, we can use backtracking to try all possible ways to use each request
// we will try to use each subset of requests and then check if the graph is valid
// at the end we will take the maximum of the number of requests used

// we can use bitmasks to represent the subsets of requests
// we can use in_deg and out_deg to check if the graph is valid
// in_deg[i] is the number of requests that end at node i
// out_deg[i] is the number of requests that start at node i
// if in_deg[i] != out_deg[i] for any node i, then the graph is not valid
// the number of requests used is the number of 1s in the bitmask

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // ans: the maximum number of requests used
        // m: the number of requests
        int ans = -1e3;
        const int m = int(requests.size());

        // try all subsets of requests
        for(int i = 0; i < 1 << m; i++) {
            // in_deg[i] is the number of requests that end at node i
            // out_deg[i] is the number of requests that start at node i
            vector<int> in_deg(n), out_deg(n);

            // try to use each request in the subset
            for(int j = 0; j < m; j++) {
                if(i & (1 << j)) {
                    int u = requests[j][0], v = requests[j][1];
                    in_deg[v]++;
                    out_deg[u]++;
                }
            }

            // check if the graph is valid
            bool valid = true;
            for(int j = 0; j < n; j++) {
                if(in_deg[j] != out_deg[j]) {
                    valid = false;
                }
            }

            // if the graph is valid, update ans with the number of requests used
            if(valid) {
                ans = max(ans, __builtin_popcount(i));
            }
        }

        return ans;
    }
};