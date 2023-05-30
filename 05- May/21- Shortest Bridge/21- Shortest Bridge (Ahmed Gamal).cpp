// Author: Ahmed Gamal

// for this problem, we just need to find the shortest path between the two islands
// we can use bfs to find the shortest path, with starting from all the cells in the first island
// and stop when we reach the second island
// to find the first island, we can use dfs (flood fill) and mark all the cells in the first island, and add them to the queue

class Solution {
    // dx, dy: arrays to represent the four directions
    using pii = pair<int, int>;
    vector<int> dx {0, 0, 1, -1}, dy {1, -1, 0, 0};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // n: size of the grid
        // q: queue to store the cells for bfs
        // vis: array to keep track of the visited cells
        const int n = int(grid.size());
        queue<pii> q;
        vector vis(n, vector(n, false));

        // valid: lambda function to check if the cell is valid or not
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 and i < n and j >= 0 and j < n and not vis[i][j];
        };

        // dfs: lambda function to mark all the cells in the first island (flood fill)
        auto dfs = [&](auto dfs, int i, int j) -> void {
            vis[i][j] = true;
            q.emplace(i, j);

            for(int d = 0; d < 4; d++) {
                int new_i = i + dx[d], new_j = j + dy[d];
                if(valid(new_i, new_j) and grid[new_i][new_j]) {
                    dfs(dfs, new_i, new_j);
                }
            }
        };

        // find the first island
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    // mark all the cells in the first island, add them to the queue, and break
                    dfs(dfs, i, j);
                    found = true;
                    break;
                }
            }
            if(found) {
                break;
            }
        }

        // bfs to find the shortest path
        // dist: distance from the first island to the second island
        int dist = 0;
        while(not q.empty()) {
            // size: number of cells in the current level
            int size = int(q.size());
            while(size--) {
                // i, j: current cell
                auto [i, j] = q.front();
                q.pop();

                // if we reached the second island, return the distance - 1 (we don't count the last cell)
                if(grid[i][j] and dist) {
                    return --dist;
                }

                // add all the valid cells to the queue
                for(int d = 0; d < 4; d++) {
                    int new_i = i + dx[d], new_j = j + dy[d];
                    if(valid(new_i, new_j)) {
                        vis[new_i][new_j] = true;
                        q.emplace(new_i, new_j);
                    }
                }
            }
            // increase the distance
            dist++;
        }

        // return any value (we will never reach this line)
        return n;
    }
};