// Author: Ahmed Gamal

// for this problem, we will use a graph to represent the bombs and their ranges
// we will create an edge between two bombs if the range of the first bomb covers the second bomb
// then, we will use DFS to find the maximum number of bombs that can be detonated (the size of the connected component that starts from the current bomb)

class Solution {
    // N: maximum number of bombs
    // adj: adjacency list of the graph
    static const int N = 101;
    vector<int> adj[N];
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // ans: maximum number of bombs that can be detonated (minimum is 1)
        int ans = 1;

        // n: number of bombs
        const int n = int(bombs.size());

        // sq: lambda function to calculate the square of a number
        auto sq = [&](long long x) -> long long {
            return x * x;
        };

        // create the graph
        for(int i = 0; i < n; i++) {
            adj[i].clear();

            // r: range of the current bomb
            // x1, y1: coordinates of the current bomb
            long long r = bombs[i][2];
            long long x1 = bombs[i][0], y1 = bombs[i][1];

            // check all other bombs                
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }

                // x2, y2: coordinates of the other bomb
                long long x2 = bombs[j][0], y2 = bombs[j][1];

                // if the range of the current bomb covers the other bomb, create an edge between them
                if(r * r >= sq(x1 - x2) + sq(y1 - y2)) {
                    adj[i].emplace_back(j);
                }
            }
        }

        // vis: bitset to keep track of the visited nodes
        bitset<101> vis;

        // dfs: lambda function to perform DFS
        auto dfs = [&](auto dfs, int src) -> int {
            // mark the current node as visited
            vis[src] = true;

            // cnt: number of bombs that can be detonated from the current bomb
            int cnt = 1;

            // try all adjacent nodes
            for(auto& nxt : adj[src]) {
                if(not vis[nxt]) {
                    cnt += dfs(dfs, nxt);
                }
            }

            // return the number of bombs that can be detonated from the current bomb
            return cnt;
        };

        // try all bombs
        for(int i = 0; i < n; i++) {
            vis.reset();
            ans = max(ans, dfs(dfs, i));
        }

        return ans;
    }
};