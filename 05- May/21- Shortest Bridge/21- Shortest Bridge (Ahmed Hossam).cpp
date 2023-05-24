// Author: Ahmed Hossam

class Solution {

    int n;
    vector < vector < int > > grid;

    // Check if the current position (r, c) is a valid position for island expansion
    bool is_valid(int r, int c, set < pair < int, int > >& isL) {
        return min(r, c) >= 0 && max(r, c) < n && !isL.count({r, c}) && grid[r][c];
    }

    // Depth-first search to expand the island
    void dfs(int r, int c, set < pair < int, int > >& isL) {
        if (!is_valid(r, c, isL)) return;
        isL.insert({r, c});  // Mark the current position as visited
        grid[r][c] = 0;     // Set the current position as water
        dfs(r + 1, c, isL);  // Check the bottom position
        dfs(r - 1, c, isL);  // Check the top position
        dfs(r, c + 1, isL);  // Check the right position
        dfs(r, c - 1, isL);  // Check the left position
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        this -> n = grid.size();
        this -> grid = grid;

        set < pair < int, int > > isl1, isl2;  // Sets to store the positions of the two islands
        bool isL = true;  // Flag to differentiate between the two islands

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y]) {
                    if (isL)
                        dfs(x, y, isl1), isL = false;  // Expand the first island
                    else
                        dfs(x, y, isl2);  // Expand the second island
                }
            }
        }

        int ans = INT_MAX;
        for (auto [x1, y1] : isl1)
            for (auto [x2, y2] : isl2)
                ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);  // Calculate the minimum distance between the two islands
            

        return ans;
    }
};

