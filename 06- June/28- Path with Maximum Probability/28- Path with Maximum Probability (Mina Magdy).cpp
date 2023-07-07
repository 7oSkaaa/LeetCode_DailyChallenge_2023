// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the maximum probability of reaching 'end' from 'start'
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create adjacency list to represent the graph
        vector<vector<pair<int, double>>> adj(n);
        
        // Create a vector to store the maximum probability for each node
        vector<double> maxprob(n);
        
        // Build the adjacency list from the given edges and success probabilities
        for (int i = 0; i < edges.size(); i++) {
            auto &v = edges[i];
            adj[v[0]].push_back({v[1], succProb[i]});
            adj[v[1]].push_back({v[0], succProb[i]});
        }
        
        // Priority queue to store nodes with their probabilities in descending order
        priority_queue<pair<double, int>> pq;
        
        // Initialize the starting node with a probability of 1
        maxprob[start] = 1;
        pq.emplace(1, start);
        
        // Perform Dijkstra's algorithm to calculate the maximum probability
        while (!pq.empty()) {
            // Get the node with the maximum probability from the priority queue
            auto [prob, cur_node] = pq.top();
            pq.pop();
            
            // If the current node is the destination node, continue to the next iteration
            if (cur_node == end) continue;
            
            // Traverse all the neighbors of the current node
            for (auto& v : adj[cur_node]) {
                // Calculate the updated probability for the neighbor
                double updated_prob = v.second * prob;
                
                // If the updated probability is greater than the maximum probability stored for the neighbor,
                // update the maximum probability and add the neighbor to the priority queue
                if (maxprob[v.first] < updated_prob) {
                    maxprob[v.first] = updated_prob;
                    pq.emplace(maxprob[v.first], v.first);
                }
            }
        }
        
        // Return the maximum probability of reaching the destination node from the starting node
        return maxprob[end];
    }
};
