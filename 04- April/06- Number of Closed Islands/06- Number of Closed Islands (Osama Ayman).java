// Author: Osama Ayman
// if the island must be closed, it can NOT reach the boundaries.
// loop over the boundaries and when you find a zero, run dfs and mark all zeros as water
// loop over the whole grid and count the number of connected compononets
class Solution {
    public int closedIsland(int[][] grid) {
        
        // top & bottom rows
        for(int i=0; i<grid[0].length; i++){
            if(grid[0][i] == 0) dfs(0,i, grid);
            if(grid[grid.length-1][i] == 0) dfs(grid.length-1,i, grid);
        }

        // left & right cols
        for(int i=1; i<grid.length-1; i++){
            if(grid[i][0] == 0) dfs(i,0, grid);
            if(grid[i][grid[0].length-1] == 0) dfs(i, grid[0].length-1, grid);
        }
        int cnt = 0;
        for(int i=1; i<grid.length-1; i++){
            for(int j=1; j<grid[0].length-1; j++){
                if(grid[i][j]==0){
                    dfs(i,j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(int r, int c, int[][] grid){
        // if out of of boundaries or this cell is visited, return
        if(r<0 || r>=grid.length || c<0 || c>=grid[0].length ||  grid[r][c] == 1) return;
        // mark as visited
        grid[r][c] = 1;
        // do the same with the neighbors
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
}