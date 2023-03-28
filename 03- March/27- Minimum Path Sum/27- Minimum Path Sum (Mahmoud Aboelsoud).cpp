// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum path sum from top left to bottom right
    // we can do this by dp

    // vectors to store the grid and dp
    vector<vector<int>> grid, dp;
    // n and m to store the size of the grid
    int n, m;

    // function to get the minimum path sum from i, j to bottom right
    int get_min(int i, int j){
        // if we are at the bottom right, return the value of the cell
        if(i == n - 1 && j == m - 1) return grid[i][j];
        // if we are out of the grid, return 1e9
        if(i >= n || j >= m) return 1e9;

        // if we have already calculated the minimum path sum from i, j to bottom right, return it
        if(dp[i][j] != -1) return dp[i][j];

        // otherwise, calculate it and return it
        return dp[i][j] = grid[i][j] + min(get_min(i + 1, j), get_min(i, j + 1)); 
    }


    int minPathSum(vector<vector<int>>& grid) {
        // store the grid and its size
        this -> grid = grid;
        n = grid.size(), m = grid[0].size();
        // assign the dp vector with -1
        dp.assign(n + 1, vector<int> (m + 1, -1));
        // return the minimum path sum from top left to bottom right
        return get_min(0, 0);
    }
};
