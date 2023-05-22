// Author : Lama Salah

class Solution {
public:
    int par[100005]; // Initialize 'par' array of size (1e5 + 5) to keep track of the parent of each node.

    // Find function to get and update the root parent of a node.
    int find(int node){
        // If the node is its own parent, return the node.
        // Otherwise, recursively find the parent and update the parent of the current node.
        return par[node] == node ? node : par[node] = find(par[node]);
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> ans; // Vector to store the smallest set of vertices.
        set <int> unique; // Set to store unique root parents.

        // Step 1: Initialize parent array for each node.
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        
        // Step 2: Iterate through the 'edges' vector and for each edge,
        // set the parent of the second node (e[1]) as the first node (e[0]).
        for (auto& e : edges) {
            par[e[1]] = e[0];
        }

        // Step 3: Find the root parent of each node and insert into the set.
        for (int i = 0; i < n; i++) {
            unique.insert(find(i));
        }

        // Step 4: Append the root parents to the result vector.
        for (auto& i : unique) {
            ans.emplace_back(i);
        }

        // Return the minimum number of vertices to reach all nodes.
        return ans;
    }
};