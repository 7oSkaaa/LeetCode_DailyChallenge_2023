// Author: Lama Salah

class Solution {
    int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};  // Possible x-direction changes.
    int dy[8] = {1, -1, 0, -1, 1, 0, -1, 1};  // Possible y-direction changes.
    int n;

public:
    // Function to check if (x, y) is within matrix boundaries.
    bool isValidCoordinate(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;  
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;  // If the starting cell is equal to 1, return -1.

        this->n = grid.size();  // Set the size of the matrix.

        // Create a queue to store cells to be visited.
        queue<vector<int>> bfsQueue;  
        bfsQueue.push({0, 0});  // Enqueue the starting cell.
        grid[0][0] = -1;  // Mark the starting cell as visited.

        // Initialize shortestPathLength to 1 (starting cell is already counted as part of the shortest path).
        int shortestPathLength = 1;  

        while (!bfsQueue.empty()){
            // Store the number of cells in the current level.
            int sizeOfQueue = bfsQueue.size();  

            while(sizeOfQueue--){
                // Dequeue a cell from the front of the queue.
                auto curr = bfsQueue.front();  
                bfsQueue.pop();

                // Check if the destination is reached (bottom-right cell).
                if (curr[0] == n-1 && curr[1] == n-1) return shortestPathLength;  

                for (int i = 0; i < 8; i++){
                    int nwx = curr[0] + dx[i];  // Calculate the new x-coordinate.
                    int nwy = curr[1] + dy[i];  // Calculate the new y-coordinate.

                    // Check if the new coordinates are valid and the cell is equal to 0.
                    if (isValidCoordinate(nwx, nwy) && !grid[nwx][nwy]){  
                        grid[nwx][nwy] = -1;  // Mark the cell as visited.
                        bfsQueue.push({nwx, nwy});  // Enqueue the cell.
                    }
                }
            }

            // Increment shortestPathLength after processing all cells in the current level.
            shortestPathLength++;  
        }

        // Return -1 if the destination cell is not reached.
        return -1;  
    }
};
