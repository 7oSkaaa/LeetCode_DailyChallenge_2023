// Author: Ahmed Gamal

// for this problem, we want to find the largest number of cells in a path that have the same color
// to solve this problem, we can use topological sort to find the longest path from each node to any of the graph's borders
// then, we can find the largest number of cells in a path that have the same color by using dynamic programming
// dp[i][j]: the largest number of cells having color j in a path that ends at node i

// but, we need to check if the graph contains a cycle, if it does, the answer is -1
// otherwise, we can use topological sort and dynamic programming to find the answer normally
// to check if the graph contains a cycle, we can use dfs to color each node with colors 0, 1, 2
// 0: unvisited node
// 1: visited node that is currently being processed
// 2: visited node that has been processed


class Solution {
    void dfs(int src, bool& found, vector<int>& color, vector<vector<int>>& adj) {
        // mark the current node as visited and currently being processed
        color[src] = 1;

        for(auto& nxt : adj[src]) {
            // if this edge leads to a node that is currently being processed, the graph contains a cycle
            if(color[nxt] == 1) {
                found = true;
            } else if(not color[nxt]) {
                // if this edge leads to an unvisited node, process it
                dfs(nxt, found, color, adj);
            }
        }

        // mark the current node as processed
        color[src] = 2;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // n: number of nodes
        // color: color of each node
        // adj: adjacency list of the graph
        // deg: in-degree of each node
        // found: true if the graph contains a cycle, false otherwise
        const int n = int(colors.size());
        vector<int> color(n + 5);
        vector adj(n + 5, vector<int>());
        vector deg(n + 5, 0);
        bool found = false;

        // build the graph
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            deg[v]++;
            adj[u].emplace_back(v);
        }

        // check if the graph contains a cycle
        for(int i = 0; i < n; i++) {
            if(not color[i]) {
                dfs(i, found, color, adj);
            }
        }

        // if the graph contains a cycle, the answer is -1
        if(found) {
            return -1;
        }

        // q: queue used in topological sort (BFS)
        // dp: dynamic programming array (dp[i][j]: the largest number of cells having color j in a path that ends at node i)
        queue<int> q;
        vector dp(n + 5, vector(26, 0));
        
        // start topological sort from nodes with in-degree 0
        for(int i = 0; i < n; i++) {
            if(not deg[i]) {
                q.emplace(i);
            }
        }

        while(not q.empty()) {
            // process the current node
            auto src = q.front();
            q.pop();

            // update the dynamic programming array
            dp[src][colors[src] - 'a']++;

            // process the next nodes
            for(auto& nxt : adj[src]) {
                // update the dynamic programming array for the next node
                for(int i = 0; i < 26; i++) {
                    dp[nxt][i] = max(dp[nxt][i], dp[src][i]);
                }

                // if the next node has in-degree 0, add it to the queue
                if(not --deg[nxt]) {
                    q.emplace(nxt);
                }
            }
        }

        // find the largest number of cells in a path that have the same color
        // the answer is the largest number of cells in a path that have the same color for any node
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
        }

        return ans;
    }
};