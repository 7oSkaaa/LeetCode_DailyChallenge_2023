// Author: Ahmed Gamal

// for this problem, we want to find the minimum path sum from the top-left cell to the bottom-right cell
// this is a classical dp problem
// dp[i][j]: the minimum path sum from the top-left cell to the cell (i, j)
// dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
// the answer is dp[n][m]

// we can optimize the space complexity to O(m) by using only one row behind the current row
// we will use two dp arrays to achieve this, dp and dp_ (dp_ is the new dp array and dp is the old dp array)
// dp[j] = the minimum path sum from the top-left cell to the cell (i, j)
// dp_[j] = the minimum path sum from the top-left cell to the cell (i + 1, j)
// dp_[j] = grid[i][j] + min(dp[j], dp_[j - 1])
// the answer is dp[m]

// after swapping dp and dp_, dp will be the old dp array and dp_ will be the new dp array
// and we can do the same thing for the next row until we reach the bottom-right cell

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // n: the number of rows
        // m: the number of columns
        const int n = int(grid.size()), m = int(grid[0].size());
        
        // dp: the dp array
        vector<int> dp(m + 1, 1e6);

        for(int i = 1; i <= n; i++) {
            // dp_: the new dp array
            vector<int> dp_(m + 1, 1e6);

            for(int j = 1; j <= m; j++) {
                // if we are in the top-left cell, then the minimum path sum is the value of this cell
                if(i == 1 and j == 1) {
                    dp_[j] = grid[i - 1][j - 1];
                    continue;
                }

                // make the transition
                dp_[j] = grid[i - 1][j - 1] + min(dp[j], dp_[j - 1]);
            }

            // swap dp and dp_
            swap(dp, dp_);
        }

        // the answer is dp[m]
        return dp[m];
    }
};