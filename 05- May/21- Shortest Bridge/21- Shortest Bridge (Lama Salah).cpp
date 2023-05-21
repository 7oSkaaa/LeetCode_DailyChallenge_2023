// Author: Lama Salah

/*

-- THE IDEA --

Use a combination of depth-first search (DFS) and breadth-first search (BFS) algorithms.
The DFS function is used to mark the first island as visited and push its cells into the queue.
The BFS function then performs a breadth-first search to find the shortest distance from the first island to the second island.

*/

class Solution {
    int n; // Size of the grid.

    // Direction arrays for exploring neighboring cells (right, left, down, up).
    int dx[4] = {0, 0, 1, -1}; 
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> grid; // Input grid
    queue<vector<int>> q; // Queue for BFS

public:
    // 'valid' function to check if coordinates (x, y) are within the grid bounds.
    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n; 
    }

    void dfs(int i, int j) {
        q.push({i, j}); // Push the current cell (i, j) into the queue.
        grid[i][j] = -1; // Mark the current cell as visited (-1).

        // Explore all four neighboring cells.
        for (int k = 0; k < 4; k++) { 
            // Calculate the new x-coordinate and y-coordinate of the neighboring cell.
            int nx = i + dx[k];
            int ny = j + dy[k]; 

            // Check if the neighboring cell is within bounds and unvisited.
            if (valid(nx, ny) && grid[nx][ny] == 1) { 
                dfs(nx, ny); // Recursively call DFS on the neighboring cell.
            }
        }
    }

    int bfs(int i, int j) {
        // Initialize the distance between the two islands as 0.
        int distance = 0; 
        
        // Process cells in the queue until it becomes empty.
        while (!q.empty()) { 
            int sz = q.size(); // Get the current number of cells in the queue.
            while (sz--) {
                // Get the front cell from the queue and pop it.
                auto curr = q.front(); 
                q.pop();

                // Explore all four neighboring cells.
                for (int k = 0; k < 4; k++) {
                    // Calculate the new x-coordinate and y-coordinate of the neighboring cell.
                    int nx = curr[0] + dx[k]; 
                    int ny = curr[1] + dy[k]; 

                    // Check if the neighboring cell is within bounds and unvisited.
                    if (valid(nx, ny) && grid[nx][ny] != -1) { 
                        // Check if the neighboring cell is the second island (the second island is found).
                        // If it is, return the current distance.
                        if (grid[nx][ny] == 1) { 
                            return distance; 
                        }

                        // Mark the neighboring cell as visited (-1).
                        grid[nx][ny] = -1; 
                        // Push the neighboring cell into the queue.
                        q.push({nx, ny}); 
                    }
                }
            }

            // Increment the distance after processing all cells in the current level.
            distance++; 
        }

        // Return the shortest distance between the two islands.
        return distance; 
    }

    int shortestBridge(vector<vector<int>>& g) {
        this->grid = g; // Store the input grid.
        this->n = grid.size(); // Get the size of the grid.

        // Iterate through the grid to find the first island.
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {
                // If a cell with value 1 is found (first island).
                if (g[i][j] == 1) { 
                    dfs(i, j); // Perform DFS to mark the first island as visited and push its cells into the queue.
                    return bfs(i, j); // Call BFS to find the shortest bridge between the two islands.
                }
            }
        }

        return 0; // If no islands are found, return 0.
    }
};
