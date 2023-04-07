// Author: Ahmed Hossam

class Solution {
public:

    // Declare variables for the size of the grid
    int n, m;

    // make the given grid global
    vector < vector < int > > grid;

    // Check if a given cell is inside the grid.
    bool is_valid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    // DFS to traverse the grid and check if a cell is part of an island.
    bool dfs(int r, int c) {
        // If the cell is not inside the grid, return false.
        if (!is_valid(r, c)) return false;
        
        // If the cell is already part of an island, return true.
        if (grid[r][c]) return true;
        
        // Mark the cell as visited by changing its value to 2.
        grid[r][c] = 2;
        
        // Traverse all the neighbors of the cell recursively and check if they are part of an island.
        bool valid = true;
        valid &= dfs(r - 1, c);
        valid &= dfs(r + 1, c);
        valid &= dfs(r, c - 1);
        valid &= dfs(r, c + 1);
        
        // Return true if all the neighbors are part of an island, false otherwise.
        return valid;
    }

    // Function to count the number of closed islands in the grid.
    int closedIsland(vector<vector<int>>& mat) {
        // Assign the input grid to the class grid variable, and get its size.
        this -> grid = mat;
        n = grid.size(), m = grid[0].size();
        
        // Initialize the answer variable to zero, and traverse the entire grid to count the number of closed islands.
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!grid[i][j])
                    ans += dfs(i, j);
        
        // Return the number of closed islands.
        return ans;
    }

};
