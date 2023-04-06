// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we just need to find how many lands we have that are totallly surrounded by water
    // if there is a land at the borders of the grid, it is not closed

    // we will use dfs to find the number of closed lands
    
    // grid: the input grid
    // vis: a 2d vector to mark the visited cells
    // n, m: the grid dimensions
    vector<vector<int>> grid, vis;
    int n, m;

    // dfs function
    // i, j: the current cell
    // f: a boolean variable to check if the current land is closed or not
    void dfs(int i, int j, bool&f){
        // if the current cell is out of the grid, or it is water, or it is visited, return
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j]) return;
        // mark the current cell as visited
        vis[i][j] = 1;

        // if the current cell is at the borders of the grid, the land is not closed
        // so we will mark f as false
        if(i == 0 || j == 0 || i == n - 1 || j == m - 1) f = 0;


        // call dfs for the 4 adjacent cells
        dfs(i + 1, j, f);
        dfs(i - 1, j, f);
        dfs(i, j + 1, f);
        dfs(i, j - 1, f);
    }

    int closedIsland(vector<vector<int>>& grid) {
        // assign the input grid to the global grid
        this -> grid = grid;
        // assign the grid dimensions to the global variables
        n = grid.size(), m = grid[0].size();
        // initialize the visited vector with zeros
        vis.assign(n, vector<int> (m, 0));

        // ans: the number of closed lands
        int ans = 0;
        // loop over the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // if the current cell is land and it is not visited, call dfs
                if(!grid[i][j] && !vis[i][j]){
                    // f: a boolean variable to check if the current land is closed or not
                    bool f = 1;
                    // call dfs
                    // f is called by reference, so if the land is closed, f will be 1 after the call of dfs function and 0 if it is not closed
                    dfs(i, j, f);
                    // if the current land is closed, increment ans by 1
                    ans += f;
                }
            }
        }
        // return the number of closed lands
        return ans;
    }
};
