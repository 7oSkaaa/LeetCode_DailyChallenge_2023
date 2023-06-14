// Author: Ahmed Hossam

class Solution {
public:

    vector < int > colour;

    // Function to check if a graph is bipartite
    bool is_Bipartite(int u, vector < vector < int > >& adj) {
        // Iterate over the adjacent vertices of u
        for (auto v : adj[u]) {
            // If v has the same color as u, the graph is not bipartite
            if (colour[v] == colour[u])
                return false;
            // If v is uncolored, assign a different color to it
            else if (colour[v] == 0) {
                colour[v] = -colour[u];
                // Recursively check if the subgraph starting from v is bipartite
                if (!is_Bipartite(v, adj))
                    return false;
            }
        }
        // All adjacent vertices have been processed and no conflict was found
        return true;
    }

    bool isBipartite(vector < vector < int > >& graph) {
        int n = graph.size();
        colour = vector < int > (n);
        
        bool isBip = true;
        // Process each vertex in the graph
        for (int u = 0; u < n; u++) {
            // If the vertex is uncolored, assign color 1 to it
            if (!colour[u]) {
                colour[u] = 1;
                // Check if the subgraph starting from u is bipartite
                isBip &= is_Bipartite(u, graph);
            }
        }

        // Return whether the graph is bipartite or not
        return isBip;
    }

};
