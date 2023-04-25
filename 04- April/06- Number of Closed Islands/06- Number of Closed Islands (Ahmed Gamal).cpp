// Author: Ahmed Gamal

// for this problem, we want to find the number of closed islands in the grid
// the closed islands are the islands that are surrounded by water from all sides
// or we can say that the closed islands are the islands that are not connected to any of the grid's borders

// we can use dfs to find the closed islands in the grid by checking if the current island is connected to any of the grid's borders

class Solution {
    // n: number of rows
    // m: number of columns
    // dx: array of possible values for the x coordinate
    // dy: array of possible values for the y coordinate
    // bounds: array of booleans that indicates if the current island is connected to any of the grid's borders
    int n, m;
    vector<int> dx {0, 0, 1, -1}, dy {-1, 1, 0, 0};
    vector<bool> bounds;

    // valid: checks if the given coordinates are valid
    bool valid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

    // dfs: performs dfs on the grid to find the closed islands
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        // mark the current cell as visited
        vis[i][j] = true;

        // iterate over the possible directions
        for(int d = 0; d < 4; d++) {
            int new_i = i + dx[d], new_j = j + dy[d];

            // if the new coordinates are valid and the new cell is not visited and not water
            if(valid(new_i, new_j)) {
                // if the new cell is not visited and not water, perform dfs on the new cell
                if(not(vis[new_i][new_j] or grid[new_i][new_j])){
                    dfs(new_i, new_j, grid, vis);
                }
            } else {
                // if the new coordinates are not valid, then the current island is connected to one of the grid's borders
                bounds[d] = true;
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        // initialize the number of rows and columns
        this -> n = (int)grid.size();
        this -> m = (int)grid[0].size();

        // vis: array of booleans that indicates if the current cell is visited or not
        vector vis(n, vector<bool>(m));

        // ans: number of closed islands
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // if the current cell is not visited and not water, perform dfs on the current cell
                if(not(grid[i][j] or vis[i][j])) {
                    // initialize the bounds array to false
                    bounds.assign(4, false);
                    dfs(i, j, grid, vis);

                    // if we didn't find any border, then the current island is closed
                    ans += not count(bounds.begin(), bounds.end(), true);
                }
            }
        }

        return ans;
    }
};