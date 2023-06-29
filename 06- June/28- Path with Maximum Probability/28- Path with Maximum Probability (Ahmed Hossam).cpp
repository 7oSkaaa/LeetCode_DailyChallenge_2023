// Author: Ahmed Hossam

class Solution {
public:

    // Struct representing a vertex in the graph
    struct Vertex {
        int u; // Vertex index
        double w; // Weight of the edge
        Vertex(int u = 0, double w = 1) : u(u), w(w) {};
        
        // Overloading the less than operator for sorting
        bool operator < (const Vertex& rhs) const {
            return w < rhs.w;
        } 
    };

    vector < vector < pair < int, double > > > adj; // Adjacency list representing the graph

    // Function to build the adjacency list
    void build_adj(int n, vector < vector < int > >& edges, vector < double >& succProb) {
        adj = vector < vector < pair < int, double > > > (n); // Initialize the adjacency list with n elements
        
        // Loop through the edges and probabilities
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].emplace_back(v, w); // Add an edge from u to v with weight w
            adj[v].emplace_back(u, w); // Add an edge from v to u with weight w
        }
    }

    // Function to find the maximum probability using Dijkstra's algorithm
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue < Vertex > dij; // Priority queue for Dijkstra's algorithm
        vector < double > dist(n, 0); // Initialize the distance vector with 0s
        build_adj(n, edges, succProb); // Build the adjacency list
        dij.emplace(start, 1); // Start vertex with probability 1
        dist[start] = 1; // Update the distance of the start vertex
        
        // Dijkstra's algorithm
        while(!dij.empty()){
            auto [u, cost] = dij.top();
            dij.pop();
            if(cost > dist[u]) continue; // Skip if a shorter path to u has already been found
            for(auto& [v, w] : adj[u]){
                if(dist[v] < cost * w){ // Update the distance if a shorter path is found
                    dist[v] = cost * w;
                    dij.emplace(v, dist[v]);
                }
            }
        }
        
        return dist[end]; // Return the maximum probability to reach the end vertex
    }
};
