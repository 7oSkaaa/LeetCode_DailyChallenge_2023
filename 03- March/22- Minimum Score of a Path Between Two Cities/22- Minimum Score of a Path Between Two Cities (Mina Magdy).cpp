// Author: Mina Magdy

// Define a class Solution
class Solution {
public:
    // Declare a vector 'vis' to keep track of visited nodes during DFS
    vector<bool> vis;
    // Declare a vector 'adj' to store the adjacency list representation of the graph
    vector<vector<pair<int, int>>> adj;
    
    // DFS traversal function
    int dfs(int u) {
        // Initialize 'ans' variable to a very large number
        int ans = 1e9;
        // Iterate over all the adjacent nodes of 'u'
        for (auto & [v, d] : adj[u]) {
            // Choose the minimum weight edge encountered so far
            ans = min(ans, d);
            // If the node 'v' has already been visited, skip it
            if (vis[v]) continue;
            // Mark the node 'v' as visited
            vis[v] = true;
            // Recursively call the 'dfs' function for the node 'v'
            // and update 'ans' variable if a smaller weight edge is encountered
            ans = min(ans, dfs(v));
        }
        // Return the minimum weight edge encountered during the DFS traversal
        return ans;
    }
    
    // Function to find the minimum score of the graph
    int minScore(int n, vector<vector<int>>& roads) {
        // Initialize the adjacency list 'adj' vector with 'n+5' empty vectors
        adj = vector<vector<pair<int, int>>>(n + 5);
        // Initialize the 'vis' vector with 'n+5' false values
        vis = vector<bool>(n + 5);
        // Iterate over all the edges in 'roads' and populate the 'adj' vector with the edge information
        for (auto& vec : roads) {
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }
        // Call the DFS traversal function 'dfs' starting from node '1'
        // and return the minimum weight edge encountered during the DFS traversal
        return dfs(1);
    }
};
