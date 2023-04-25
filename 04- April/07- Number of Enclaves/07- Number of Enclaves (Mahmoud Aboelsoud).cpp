// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the number of islands that are not connected to the border
    // so we can use dfs to find the number of islands and check if it is connected to the border or not
    // if it is connected to the border then we can't count it
    // if it is not connected to the border then we can count it

    // vis: to mark the visited cells
    // grid: the input grid
    vector<vector<int>> vis, grid;
    // n, m: the dimensions of the grid
    int n, m;

    // to check if the current cell is valid or not
    bool vaild(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j];
    }

    // dfs to find the number of islands and check if it is connected to the border or not
    // cnt: to count the number of cells in the current island
    // f: to check if the current island is connected to the border or not
    void dfs(int i, int j, int&cnt, bool&f){
        // if the current cell is not valid then return
        if(!vaild(i, j)) return;
        // mark the current cell as visited
        vis[i][j] = 1;
        // increase the number of cells in the current island
        cnt++;
        // if the current cell is on the border then the current island is connected to the border
        if(i == 0 || i == n - 1 || j == 0 || j == m - 1) f = 0;

        // dfs in the 4 directions
        dfs(i + 1, j, cnt, f);
        dfs(i - 1, j, cnt, f);
        dfs(i, j + 1, cnt, f);
        dfs(i, j - 1, cnt, f);
    }


    int numEnclaves(vector<vector<int>>& grid) {
        // assign the input grid to the grid variable
        this -> grid = grid;
        // assign the dimensions of the grid
        n = grid.size(), m = grid[0].size();
        // assign the vis vector with the dimensions of the grid
        vis.assign(n, vector<int> (m, 0));
        
        // ans: to count the number of islands that are not connected to the border
        int ans = 0;
        // loop on the grid
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                // if the current cell is not visited and it is land then we can start dfs from it
                if(!vis[i][j] && grid[i][j]){
                    // f: to check if the current island is connected to the border or not
                    // cnt: to count the number of cells in the current island
                    bool f = 1;
                    int cnt = 0;
                    // start dfs from the current cell
                    dfs(i, j, cnt, f); 
                    // if the current island is not connected to the border then we can count it 
                    ans += f * cnt;
                }
            }
        }

        // return the number of islands that are not connected to the border
        return ans;
    }
};
