// Author: Osama Ayman
class Solution {
    // DP Solution
    // Time O(n*m)
    // Space O(1)
    public int minPathSum(int[][] grid) {
        // first row has only 1 option: move right
        for(int j=1; j<grid[0].length; j++){
            grid[0][j]+=grid[0][j-1];
        }
        //first col has only 1 option: move down
        for(int i=1; i<grid.length; i++){
            grid[i][0]+=grid[i-1][0];
        }
        // starting from second row, second col each cell has 2 options: right and down
        for(int i=1; i<grid.length; i++){
            for(int j=1; j<grid[0].length; j++){
                grid[i][j]+=Math.min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
