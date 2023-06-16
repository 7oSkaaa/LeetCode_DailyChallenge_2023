// Author: Ahmed Gamal

// counting the number of provinces is the same as counting the number of connected components in the graph
// so, we will use DFS to find the number of connected components in the graph
// but, we will use here the adjacency matrix representation of the graph instead of the adjacency list representation

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // n: number of cities
        // vis: bitset to keep track of the visited cities
        const int n = int(isConnected.size());
        bitset<202> vis;

        // dfs: lambda function to perform DFS
        auto dfs = [&](auto dfs, int src) -> void {
            // mark the current city as visited
            vis[src] = true;

            // check all cities that are connected to the current city
            for(int j = 0; j < n; j++) {
                if(isConnected[src][j] and not vis[j]) {
                    dfs(dfs, j);
                }
            }
        };

        // cnt: number of provinces
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(not vis[i]) {
                dfs(dfs, i);
                cnt++;
            }
        }

        return cnt;
    }
};