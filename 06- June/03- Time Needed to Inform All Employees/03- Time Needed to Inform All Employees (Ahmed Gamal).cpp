// Author: Ahmed Gamal

// we will solve this problem depending on the fact that if the order starts propagating from the head, then the time needed to inform all the employees will be the maximum time to reach a leaf node
// so, we will create a graph to represent the hierarchy of the employees
// then, we will use DFS to find the maximum time to reach a leaf node

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // adj: adjacency list of the graph
        vector<vector<int>> adj(n);

        // create the graph
        for(int i = 0; i < n; i++) {
            // if the current employee is the head, then continue
            if(!~manager[i]) {
                continue;
            }
            // add an edge between the current employee and his manager
            adj[manager[i]].emplace_back(i);
        }

        auto dfs = [&](auto dfs, int src) -> int {
            // the time needed to inform the current employee (the time needed to inform his employees)
            int curr = informTime[src];
            int ret = 0;

            // check all employees that are managed by the current employee
            // and find the maximum time needed to inform them
            for(auto& nxt : adj[src]) {
                ret = max(ret, curr + dfs(dfs, nxt));
            }
            return ret;
        };

        // start DFS from the head
        return dfs(dfs, headID);
    }
};