// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the maximum number of detonations
    int maximumDetonation(vector<vector<int>>& bombs) {
        // Lambda function to check if two bombs intersect
        auto isIntersect = [&](int i, int j) {
            long long x = bombs[i][0] - bombs[j][0];
            long long y = bombs[i][1] - bombs[j][1];
            long long d = x * x + y * y;
            long long z = bombs[i][2];
            return d <= z * z;
        };

        int n = bombs.size(); // Number of bombs
        vector<vector<int>> adj(n); // Adjacency list to represent connections

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (isIntersect(i, j))
                    adj[i].push_back(j);
            }
        }

        int ans = 0; // Maximum number of detonations

        // Perform BFS on each bomb
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n); // Visited array
            int cnt = 1; // Count of detonations
            queue<int> bfs;
            bfs.push(i);
            vis[i] = true;

            // BFS traversal
            while (!bfs.empty()) {
                int u = bfs.front();
                bfs.pop();

                // Explore adjacent bombs
                for (auto& v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        cnt++;
                        bfs.push(v);
                    }
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
