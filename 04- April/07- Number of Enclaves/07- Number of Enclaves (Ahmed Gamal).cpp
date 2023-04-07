// Author: Ahmed Gamal

// for this problem, we want to find the number of closed island cells in the grid
// to solve this problem, we can use the same idea of the previous problem, but we need to count the number of cells in the current island
// and add it to the answer if the current island is not connected to any of the grid's borders

class Solution {
    int n, m;
    vector<int> dx {0, 0, 1, -1}, dy {-1, 1, 0, 0};
    vector<bool> bounds;

    bool valid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

    void dfs(int i, int j, int& cnt, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        // count the number of cells in the current island
        cnt++;

        for(int d = 0; d < 4; d++) {
            int new_i = i + dx[d], new_j = j + dy[d];
            if(valid(new_i, new_j)) {
                if(not vis[new_i][new_j] and grid[new_i][new_j]){
                    dfs(new_i, new_j, cnt, grid, vis);
                }
            } else {
                bounds[d] = true;
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this -> n = (int)grid.size();
        this -> m = (int)grid[0].size();
        vector vis(n, vector<bool>(m));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] and not vis[i][j]) {
                    bounds.assign(4, false);
                    // cnt: number of cells in the current island
                    int cnt = 0;
                    dfs(i, j, cnt, grid, vis);

                    // if the current island is not connected to any of the grid's borders, add the number of cells in the current island to the answer
                    ans += not count(bounds.begin(), bounds.end(), true) * cnt;
                }
            }
        }

        return ans;
    }
};