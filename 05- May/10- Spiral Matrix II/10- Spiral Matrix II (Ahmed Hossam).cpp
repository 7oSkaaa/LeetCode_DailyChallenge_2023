// Author: Ahmed Hossam

class Solution {
public:

    // Check if (x, y) is inside the grid with size n
    bool onGrid(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    // Generate a matrix with size n x n in a spiral pattern
    vector<vector<int>> generateMatrix(int n) {
        // Define the directions to move in the spiral pattern
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        
        // Initialize the matrix with all zeros
        vector<vector<int>> ret(n, vector<int>(n));
        
        // Set the starting position to (0, 0) and initialize the counter to 1
        int dir = 0, cnt = 0, x = 0, y = 0;
        ret[x][y] = ++cnt;
        
        // Keep moving in the spiral pattern until all elements are filled
        while (cnt < n * n) {
            // Compute the next position to move to
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            
            // If the next position is not inside the grid, change direction and continue
            if (false == onGrid(xx, yy, n)) {
                dir = (dir + 1) % 4;
                continue;
            }
            
            // If the next position is already filled, change direction and continue
            if (ret[xx][yy] != 0) {
                dir = (dir + 1) % 4;
                continue;
            }
            
            // Move to the next position and fill it with the next counter value
            x = xx, y = yy;
            ret[x][y] = ++cnt;
        }
        
        // Return the generated matrix
        return ret;
    }

};
