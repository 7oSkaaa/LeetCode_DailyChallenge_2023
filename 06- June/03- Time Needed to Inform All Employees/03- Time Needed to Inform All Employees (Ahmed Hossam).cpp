// Author: Ahmed Hossam

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create an adjacency list to represent the organizational structure
        vector < vector < int > > adj(n);
        
        // Build the adjacency list
        for (int v = 0, u = manager[v]; v < n; v++, u = manager[v])
            if (~u) 
                adj[u].push_back(v);
        
        // Initialize distance vector to store the time taken for each employee to be informed
        vector < int > dist(n, -1);
        
        // Create a queue for breadth-first search
        queue < int > bfs;
        
        // Start from the head employee
        dist[headID] = 0;
        bfs.push(headID);
        
        // Perform breadth-first search
        while (!bfs.empty()) {
            // Get the front employee from the queue
            auto u = bfs.front();
            bfs.pop();
            
            // Traverse the employees under the current employee
            for (auto& v : adj[u]) {
                // If the employee hasn't been informed yet, update the distance and add to the queue
                if (dist[v] == -1) {
                    bfs.push(v);
                    dist[v] = dist[u] + informTime[u];
                }
            }
        }
        
        // Return the maximum inform time from the distance vector
        return *max_element(dist.begin(), dist.end());
    }
};
