// Author: Mina Magdy

class Solution {
public:
    // Defining the required variables
    string colors;
    vector<vector<int>> adj;
    vector<int> vis;

    // Function to calculate the longest path starting from a node 'u' with color 'c'
    int dfs(int u, char c) {
        // Marking the node as visited
        vis[u] = 0;
        // Checking for all its adjacent nodes
        for (auto& v : adj[u]) {
            // Updating the visit status of node u
            vis[u] = max(vis[u], (~vis[v] ? vis[v] : dfs(v, c)));
        }
        // Adding 1 to the count if the color matches with the required color
        return vis[u] += (colors[u] == c);
    }

    // Function to check if there exists a cycle in the graph
    bool is_cycle(int u) {
        // If the node is already visited once, that means there is a cycle
        if (vis[u]) return vis[u] == 1;
        // Marking the node as visited
        vis[u] = 1;
        // Checking for all its adjacent nodes
        for (auto& v : adj[u]) {
            if (is_cycle(v)) return true;
        }
        // Marking the node as visited twice to show it's fully visited
        vis[u] = 2;
        return false;
    }

    // Function to calculate the largest path value
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // Initializing the variables
        this->colors = colors;
        int n = colors.size();
        adj.resize(n);
        // Creating an adjacency list
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
        }
        vis.assign(n, 0);
        // Checking if there is a cycle in the graph
        for (int i = 0; i < n; i++)
            if (is_cycle(i)) return -1;

        int ans = 0;
        // For each color, calculating the maximum path value
        for (char c = 'a'; c <= 'z'; c++) {
            vis.assign(n, -1);
            for (int i = 0; i < n; i++) {
                ans = max(ans, (~vis[i] ? vis[i] : dfs(i, c)));
            }
        }
        // Returning the maximum path value
        return ans;
    }
};
