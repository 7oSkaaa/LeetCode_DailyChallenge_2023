//Author: Mohamed Ibrahim

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create 2D vector for storing flight information
        vector<vector<pair<int, int>>> adj(n);
        // Iterate through input flights and add to adjacency list
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        // Create vector to store minimum distances to each node
        vector<int> dist(n, numeric_limits<int>::max());
        // Create queue to keep track of minimum distances
        queue<pair<int, int>> q;
        // Push the source node and distance of 0 into the queue
        q.push({src, 0});
        // Initialize variable to keep track of number of stops
        int stops = 0;

        // Continue while number of stops is less than or equal to k and queue is not empty
        while (stops <= k && !q.empty()) {
            // Get the size of the queue
            int sz = q.size();
            // Iterate on current level
            while (sz--) {
                // Get the front element from the queue
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbours of popped node
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        // Return -1 if there is no route from src to dst
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
