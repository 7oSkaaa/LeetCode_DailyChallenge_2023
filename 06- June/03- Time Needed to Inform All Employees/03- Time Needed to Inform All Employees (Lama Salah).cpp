// Author: Lama Salah

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create an adjacency list to represent the company tree.
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            if (~manager[i])
                adj[manager[i]].push_back(i);
        }

        // Create a queue for BFS traversal, starting with the head employee.
        queue<pair<int, int>> BFSqueue;
        BFSqueue.push({headID, 0});

        int needed_minutes = 0;
        while (!BFSqueue.empty()) {
            // Get the node and the time taken to inform that node from the front of the queue.
            auto [node, time] = BFSqueue.front();
            BFSqueue.pop();

            // Update the maximum time taken to inform any employee.
            needed_minutes = max(needed_minutes, time);

            // Traverse the neighbors of the current node.
            for (auto& neighbour : adj[node]) {
                // Add the neighbor to the queue, considering the time taken to inform the current node.
                BFSqueue.push({neighbour, time + informTime[node]});
            }
        }

        // Return the maximum time taken to inform all employees.
        return needed_minutes;
    }
};