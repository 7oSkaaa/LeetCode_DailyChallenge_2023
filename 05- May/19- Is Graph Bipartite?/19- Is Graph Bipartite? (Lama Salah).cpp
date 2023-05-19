// Author: Lama Salah

class Solution {
public:
    vector<vector<int>> adj; // Adjacency list to represent the graph.
    vector<int> vis; // Array to keep track of node colors.

    // Recursive function to check if the graph is not bipartite.
    bool isNotBipartite(int node, int color) {
        vis[node] = color; // Assign the current node the specified color (0 or 1).

        bool ans = false; // Variable to store the result.

        for (auto& i : adj[node]) {
            if (vis[i] == -1) {
                // If the neighbor hasn't been visited, recursively call the function with the opposite color.
                ans |= isNotBipartite(i, color ^ 1);
            } else if ((color ^ 1) != vis[i]) {
                // If the neighbor has been visited and has the same color as the current node, the graph is not bipartite.
                return true;
            }
        }

        return ans;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        adj.assign(graph.size(), vector<int>()); // Initialize the adjacency list.
        vis.assign(graph.size(), -1); // Initialize the vis array.

        // Build the adjacency list based on the given graph.
        for (int i = 0; i < graph.size(); i++) {
            for (auto& j : graph[i]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        // Iterate over each node in the graph.
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == -1 && isNotBipartite(i, 0)) {
                // If the node hasn't been visited and the graph is not bipartite, return false.
                return false;
            }
        }

        return true; // The graph is bipartite.
    }
};