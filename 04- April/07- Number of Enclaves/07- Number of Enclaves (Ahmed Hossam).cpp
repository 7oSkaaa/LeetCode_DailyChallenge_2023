// Author: Ahmed Hossam

class Solution {
public:
    
    // Initializing two 2D vectors to store the grid values
    vector < vector < int > > grid;

    // Variables for the dimensions of the grid
    int n, m;

    // Function to check if a cell is valid
    bool is_valid(int r, int c){
        return r >= 0 && c >= 0 && r < n && c < m && grid[r][c];
    }

    // Depth first search function
    int dfs(int r, int c){
        // If the cell is not valid return 0
        if(!is_valid(r, c)) return 0;

        // Set the cell as visited
        grid[r][c] = 0;
        
        // Return 1 plus the results of the DFS of the adjacent cells
        return 1 + dfs(r + 1, c) + dfs(r, c + 1) + dfs(r - 1, c) + dfs(r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // Set the grid dimensions
        this -> grid = grid;
        n = grid.size(), m = grid[0].size();
                
        // Perform DFS on all cells on the border
        for(int i = 0; i < n; i++) dfs(i, 0); // left border
        for(int i = 0; i < n; i++) dfs(i, m - 1); // right border
        for(int i = 0; i < m; i++) dfs(0, i); // upper border
        for(int i = 0; i < m; i++) dfs(n - 1, i); // lower border
        
        // Count the number of enclaves by performing DFS on each valid cell
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(is_valid(i, j))
                    cnt += dfs(i, j);
        
        // Return the count of enclaves
        return cnt;
    }

};
