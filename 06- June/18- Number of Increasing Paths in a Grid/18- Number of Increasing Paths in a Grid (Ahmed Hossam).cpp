// Author: Ahmed Hossam

class Solution {
public:

    int n, m; // Variables to store the dimensions of the grid
    vector < vector < int > > dp, grid; // 2D vectors to store dynamic programming values and the grid itself
    vector < pair < int, int > > dir; // Vector of pairs to store the possible directions to move
    static constexpr int MOD = 1e9 + 7; // Constant variable to represent the modulo value

    void add(int& a, int b){
        a += b; // Add 'b' to 'a'
        if(a >= MOD) a -= MOD; // If 'a' exceeds the modulo value, subtract the modulo value from 'a'
    }

    bool is_valid(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < m; // Check if the indices 'r' and 'c' are within the grid boundaries
    }

    int get_paths(int x, int y){
        int& ret = dp[x][y]; // Reference to store the dynamic programming value for coordinates (x, y)
        if(~ret) return ret; // If the value is already computed, return it
        ret = 1; // Set the initial value of 'ret' to 1
        for(auto& [dx, dy] : dir){ // Iterate over the possible directions to move
            int nx = dx + x, ny = dy + y; // Calculate the new coordinates based on the direction
            if(is_valid(nx, ny) && grid[nx][ny] > grid[x][y]) // Check if the new coordinates are valid and the value at the new position is greater than the current position
                add(ret, get_paths(nx, ny)); // Recursively calculate the number of paths from the new position and add it to 'ret'
        }
        return ret; // Return the number of paths from position (x, y)
    }

    int countPaths(vector<vector<int>>& grid) {
        this -> grid = grid; // Store the input grid in the class member variable
        n = grid.size(), m = grid[0].size(); // Get the dimensions of the grid
        dp = vector < vector < int > > (n, vector < int > (m, -1)); // Initialize the dynamic programming values with -1
        dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // Set the possible directions to move (right, left, down, up)
        int paths = 0; // Variable to store the total number of paths
        for(int i = 0; i < n; i++) // Iterate over each row of the grid
            for(int j = 0; j < m; j++) // Iterate over each column of the grid
                add(paths, get_paths(i, j)); // Add the number of paths from each position to 'paths'
        return paths; // Return the total number of paths
    }
};
