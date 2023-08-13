// Author: Ahmed Hossam

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Get the number of rows and columns in the obstacleGrid
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        // Initialize a 2D vector dp with dimensions (n+5) x (m+5)
        vector<vector<int>> dp(n + 5, vector<int>(m + 5));
        
        // Set the starting point in dp based on the condition in obstacleGrid
        dp[1][1] = (obstacleGrid[0][0] != 1);
        
        // Iterate through each cell in the obstacleGrid
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Check if the current cell is not an obstacle
                if(obstacleGrid[i - 1][j - 1] != 1) {
                    // Calculate the number of unique paths to the current cell
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        // Return the number of unique paths to the bottom-right cell of the obstacleGrid
        return dp[n][m];
    }
};
