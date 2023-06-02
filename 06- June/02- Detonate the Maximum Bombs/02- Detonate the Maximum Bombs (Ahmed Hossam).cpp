// Author: Ahmed Hossam

class Solution {
public:

    vector<vector<int>> adj; // Adjacency list representing the graph.
    vector<bool> vis; // Boolean array to keep track of visited nodes.

    // Function to check if a circle is intersect another circle.
    bool isIntersect(const vector<int>& a, const vector<int>& b){
        int X = (a[0] - b[0]), Y = (a[1] - b[1]), R = a[2];
        return (1ll * R * R) >= (1ll * X * X) + (1ll * Y * Y); 
    }

    // Depth-first search function to calculate the length of a path.
    int dfs(int u){
        vis[u] = true; // Mark the current node as visited.
        int pathLength = 1; // Initialize the path length to 1 for the current node.
        for(auto& v : adj[u]){ // Iterate through the adjacent nodes of the current node.
            if(!vis[v]) // If the adjacent node is not visited, recursively call dfs on it.
                pathLength += dfs(v); // Add the path length of the adjacent node to the current path length.
        }
        return pathLength; // Return the total path length.
    }

    // Function to build the adjacency list based on the given bombs coordinates.
    void build_adj(const vector<vector<int>>& bombs){
        int n = bombs.size();
        adj = vector<vector<int>>(n + 5); // Initialize the adjacency list.
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isIntersect(bombs[i], bombs[j])){ // Check if bomb j is intersect bomb i.
                    adj[i].push_back(j); // Add j to the adjacency list of i.
                }
            }
        }
    }

    // Function to calculate the maximum detonation path length.
    int maximumDetonation(const vector<vector<int>>& bombs) {
        int n = bombs.size(); // Get the number of bombs.
        
        build_adj(bombs); // Build the adjacency list.
        
        int maxPathLength = 0; // Initialize the maximum path length to 0.
        for(int i = 0; i < n; i++){ // Iterate through each bomb.
            vis = vector<bool>(n + 5); // Reset the visited array.
            maxPathLength = max(maxPathLength, dfs(i)); // Calculate the maximum path length starting from bomb i.
        }
        
        return maxPathLength; // Return the maximum path length.
    }
};
