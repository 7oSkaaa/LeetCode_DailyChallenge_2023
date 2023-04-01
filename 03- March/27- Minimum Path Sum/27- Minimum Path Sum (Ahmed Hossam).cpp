// Author: Ahmed Hossam

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        int n = grid.size(), m = grid[0].size();
        
        // Initialize a 2D vector 'dp' to store minimum path sums for each cell in the grid
        // 'dp' is initialized to a large value so that it can be easily updated with smaller values later
        vector < vector < int > > dp(n + 5, vector < int > (m + 5, 1e9));
        
        // Initialize the top-left and top-right cells to 0, since the minimum path sum to those cells is 0
        dp[0][1] = dp[1][0] = 0;
        
        // Iterate through each cell in the grid
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                // Calculate the minimum path sum to reach the current cell
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) +  grid[i - 1][j - 1];
                // The above line of code calculates the minimum path sum to reach the cell (i,j) in the grid
                // It does this by comparing the minimum path sum to reach the cell above (i-1, j) and the cell to the left (i, j-1)
                // The minimum path sum is then updated to include the current cell's value (grid[i-1][j-1])
        
        // Return the minimum path sum to the bottom-right cell (i.e., the last element in 'dp')
        return dp[n][m];
    }
};
