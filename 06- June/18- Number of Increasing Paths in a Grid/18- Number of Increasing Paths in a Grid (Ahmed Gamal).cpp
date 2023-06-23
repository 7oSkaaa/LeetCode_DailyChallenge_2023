// Author: Ahmed Gamal

// for this problem we will use dynamic programming to count the number of increasing paths from each cell
// we will solve the problem iteratively, but first we need to know the toplogical order of the cells to be calculated in the dp table
// if we notice that the cells in which we will stop are the cells with the maximum value in the grid, because there is no cell with a greater value than it
// and these cells (if we started from them) will only have one path to reach them, which is the path from them to themselves
// and the next smaller cells will have a number of paths equal to the sum of the number of paths of the cells that are greater than them and adjacent to them
// dp[i][j] = sum(dp[new_i][new_j]) where new_i and new_j are the adjacent cells to the cell i, j and grid[new_i][new_j] > grid[i][j]
// so we will use a priority queue to get the cells in the toplogical order, and we will use a 2D array to store the number of paths from each cell
// and since we need to count the number of paths from each cell, we will add the number of paths from each cell to the answer when we complete its calculations

class Solution {
    // MOD: is the modulo value
    // n, m: the dimensions of the grid
    // dp: the 2D array to store the number of paths from each cell
    // dx, dy: the directions to move in the grid (right, left, down, up)
    static const int MOD = 1e9 + 7;
    int n, m;
    vector<vector<int>> dp;
    vector<int> dx {0, 0, 1, -1}, dy {1, -1, 0, 0};

    // function to check if the cell (i, j) is valid (inside the grid)
    bool valid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        // initialize the variables
        n = (int)grid.size();
        m = (int)grid.front().size();

        // initialize the priority queue and the dp table
        // the priority queue will store the cells in the toplogical order as tuples (value, i, j)
        priority_queue<tuple<int, int, int>> pq;
        dp.assign(n + 5, vector<int>(m + 5, 1));

        // add the cells to the priority queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pq.emplace(grid[i][j], i, j);
            }
        }

        // ans: the answer
        int ans = 0;

        // loop on the cells in the toplogical order
        while(not pq.empty()) {
            // get the cell with the maximum value
            auto [val, i, j] = pq.top();
            pq.pop();

            // loop on the adjacent cells
            for(int d = 0; d < 4; d++) {
                int new_i = i + dx[d], new_j = j + dy[d];

                // if the adjacent cell is valid and its value is greater than the current cell
                if(valid(new_i, new_j) and grid[new_i][new_j] > grid[i][j]) {
                    // add the number of paths from the adjacent cell to the current cell
                    dp[i][j] += dp[new_i][new_j];
                    dp[i][j] %= MOD;
                }
            }

            // add the number of paths from the current cell to the answer
            ans += dp[i][j];
            ans %= MOD;
        }

        return ans;
    }
};