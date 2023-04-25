// Author: Osama Ayman
// Time: O(n*m)
// Space: O(1)

// if we can walk to the boundary of the grid, there must be at least 1 connected lan cell that touches the boundaries.

// So, loop over the boundaries, when you find a land cell, run dfs to mark all coneected cells as reachable (can walk from them to the boundary). We will mark them by converting them to zeros

// All cells that are still ones (lands) have no walk to reach the boundary. So, count them and this is the result.
class Solution {
    public int numEnclaves(int[][] grid) {
        // left and right cols
        for(int i=0; i<grid.length; i++){
            if(grid[i][0] == 1) dfs(i,0,grid);
            if(grid[i][grid[0].length-1] == 1) dfs(i, grid[0].length-1, grid);
        }
        // top  and bottom rows
        for(int j=0; j<grid[0].length; j++){
            if(grid[0][j] == 1) dfs(0,j,grid);
            if(grid[grid.length-1][j] == 1) dfs(grid.length-1, j, grid);
        }
        int cnt = 0;
        for(int i=1; i<grid.length; i++){
            for(int j=1; j<grid[0].length; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
    void dfs(int r, int c, int[][] grid){
        if(r<0 || r>=grid.length || c<0 || c>=grid[0].length || grid[r][c] == 0) return;
        grid[r][c] = 0;
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }
}