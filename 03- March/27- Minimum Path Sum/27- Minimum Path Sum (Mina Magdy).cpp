// Author: Mina Magdy

// Solution class definition
class Solution {
public:
    // A 2D vector to store dynamic programming results
    vector<vector<int>> dp;
    
    // Solution class constructor to initialize the dynamic programming vector with -1
    Solution() {
        dp.assign(200, vector<int>(200, -1));
    }
    
    // A function to find the minimum path sum of a grid
    int minPathSum(vector<vector<int>>& grid, int i = 0, int j = 0) {
        // Invalid base case: If the current position is out of grid, return a large number
        if (i == grid.size() || j == grid[i].size()) return 1e9;
        
        // Valid base case: If the current position is at the bottom right of the grid, return the value of the current position
        if (i == grid.size() - 1 && j == grid[i].size() - 1) return grid[i][j];
        
        // If the dynamic programming vector has already stored the result of the current position, return it
        if (~dp[i][j]) return dp[i][j];
        
        // If the dynamic programming vector has not stored the result of the current position, compute and store it
        return dp[i][j] = grid[i][j] + min(minPathSum(grid, i + 1, j), minPathSum(grid, i, j + 1));
    }
};
