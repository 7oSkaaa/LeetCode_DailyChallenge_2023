// Author: Lama Salah

class Solution {
    // Adjacency list to represent the graph and visited array.
    vector<int> adjacencyList[105], vis; 

public:
    // Function to check if two bombs intersect.
    bool checkIntersection(vector<int>& bomb1, vector<int>& bomb2) {
        long long x1 = bomb1[0], y1 = bomb1[1], r1 = bomb1[2]; 
        long long x2 = bomb2[0], y2 = bomb2[1], r2 = bomb2[2]; 

        // Calculating the distance between bomb1 and bomb2.
        long double distance = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 

        // If the distance is less than or equal to the radius of bomb1 (bomb2 lies within bomb1's range), return true.
        if (distance <= r1) return true; 

        return false; // Otherwise, return false.
    }

    int dfs(int node) {
        vis[node] = 1; // Marking the current node as visited.

        // Initializing the count of bombs that can be detonated from the current node.
        int detonation_count = 1; 

        // Traverse all neighbors of the current node.
        for (auto& neighbor : adjacencyList[node]) {
            if (!vis[neighbor]) { 
                // Recursively perform DFS on the unvisited neighbor and add the count of detonatable bombs.
                detonation_count += dfs(neighbor); 
            }
        }

        // Return the total count of bombs that can be detonated from the current node.
        return detonation_count; 
    }

    // Function to calculate the maximum number of bombs that can be detonated.
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(); // Number of bombs.
        vis.assign(n, 0); // Initialize the visited array with zeros.

        // Build the adjacency list.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && checkIntersection(bombs[i], bombs[j])) {
                    // Add an edge between bombs i and j if bomb j lies within bomb i's range.
                    adjacencyList[i].push_back(j); 
                }
            }
        }

        // Variable to store the maximum count of bombs that can be detonated.
        int maxDetonation = 0; 

        for (int i = 0; i < n; i++) {
            // Reset the visited array for each DFS traversal.
            vis.assign(n, 0); 

            // Perform DFS from node i and update the maximum count.
            maxDetonation = max(maxDetonation, dfs(i)); 
        }

        // Return the maximum count of bombs that can be detonated.
        return maxDetonation; 
    }
};