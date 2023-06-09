// Author: Ahmed Gamal

// for this problem, we will use BFS to find the shortest path from the top left cell to the bottom right cell

class Solution {
public:
    // n: number of rows, m: number of columns
    // dx: vector of the horizontal directions, dy: vector of the vertical directions
    int n, m;
    vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1}, dy = {1, -1, 0, 0, 1, -1, 1, -1};
    
    // check if the given cell is valid
    bool is_valid(int x, int y){
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // if the top left cell is blocked, return -1
        if(grid[0][0])
            return -1;
        
        // initialize the number of rows and columns
        // ans: 2D array to keep track of the shortest path from the top left cell to the current cell
        n = int(grid.size()), m = int(grid.front().size());
        int ans[n][m];
        
        // initialize the 2D array with -1
        memset(ans, -1, sizeof ans);
        
        // initialize the queue and push the top left cell, and set its shortest path to 0
        queue<pair<int, int>> q;
        q.push({0, 0});
        ans[0][0] = 0;
        
        // while the queue is not empty, keep searching for the shortest path
        while(not q.empty()){
            // get the front of the queue
            auto [x, y] = q.front();
            q.pop();
            
            // try all possible directions
            for(int i = 0; i < dx.size(); i++){
                int new_x = x + dx[i], new_y = y + dy[i];
                // if the new cell is valid, not visited, and not blocked, set its shortest path to the current cell + 1
                if(is_valid(new_x, new_y) and ans[new_x][new_y] == -1 and not grid[new_x][new_y]){
                    ans[new_x][new_y] = ans[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }
        
        // get the shortest path from the top left cell to the bottom right cell
        int ret = ans[--n][--m];
        
        // if the shortest path is -1, return -1, otherwise, return the shortest path + 1 (because we need to count the top left cell)
        return ~ret ? ++ret : ret;
    }
};