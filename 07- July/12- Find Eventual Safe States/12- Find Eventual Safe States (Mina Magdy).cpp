// Author: Mina Magdy

class Solution {
public:
    // Declare two vectors to keep track of the colors of the nodes and whether they belong to a cycle or not.
    vector<int> color;
    vector<bool> cycle;
    int n;
    
    // Define a depth-first search function that takes a node and the graph as input.
    void dfs(int u, vector<vector<int>>& graph) {
        // If the node has already been visited, check if it is not marked as fully explored (in cycle).
        if (color[u]) {
            cycle[u] = cycle[u] || (color[u] != 2);
            return;
        }
        
        // Mark the node as visited and explore its neighbors recursively.
        color[u] = 1;
        for (auto& v : graph[u]) {
            dfs(v, graph);
            cycle[u] = cycle[u] || (cycle[v]);
        }
        
        // Mark the node as fully explored.
        color[u] = 2;
    }
    
    // Define a function that takes a graph as input and returns a vector of nodes that are eventually safe.
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        
        // Initialize the color vector to all zeros and the cycle vector to all false values.
        color.assign(n, 0);
        cycle.assign(n, false);
        
        // For each node in the graph, perform a depth-first search to determine if it belongs to a cycle or not.
        for (int i = 0; i < n; i++) {
            dfs(i, graph);
        }
        
        // Create a vector to store the nodes that are eventually safe.
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (!cycle[i])
                vec.push_back(i);
        }
        
        // Return the vector of eventually safe nodes.
        return vec;
    }
};
