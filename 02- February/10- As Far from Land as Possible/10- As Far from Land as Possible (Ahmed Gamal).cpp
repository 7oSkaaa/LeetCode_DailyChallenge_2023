// Author: Ahmed Gamal

class Solution {
public:
    
    // for this problem we want to find the farthest water point from the land
    // the trivial solution is to run bfs from each land point and find the farthest water point and return the maximum of them
    // but this solution will take O(n^4) time
    // for this problem we don't need to run bfs from each land point because we just need to find the farthest water point from any land point (not specific to one land point)
    // so we can run bfs with all the points that have land as a source at the same time and find the farthest water point from all the land points
    // this solution will take O(n^2)


    // dx and dy are the 4 directions we can move in the grid
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    
    // n is the size of the grid
    int n;

    // valid function to check if the current point is inside the grid or not
    bool valid(int x, int y){
        return x >= 0 and x < n and y >= 0 and y < n;
    }

    int maxDistance(vector<vector<int>>& grid) {
        // initialize n
        this -> n = (int)grid.size();

        // q is the queue that will be used in bfs
        queue<pair<int, int>> q;
        
        // d is the distance array
        int d[100][100];

        // initialize d with -1 to mark unvisited points
        memset(d, -1, sizeof d);
    

        // ans is the answer (maximum distance from any land point that we can reach)
        int ans = -1;

        // see all the land points and push them into the queue to start bfs from them
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    d[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while(not q.empty()){
            // size is the number of points in the current level
            int size = int(q.size());

            // see all the points in the current level
            while(size--){
                // get the current point
                auto [x, y] = q.front();
                q.pop();
            
                // see all the 4 directions (up, down, right, left)
                for(int i = 0; i < 4; i++){
                    // nxt_x and nxt_y are the next point in the current direction
                    int nxt_x = x + dx[i];
                    int nxt_y = y + dy[i];

                    // if the next point is inside the grid and it is not visited yet
                    if(valid(nxt_x, nxt_y) and d[nxt_x][nxt_y] == -1){
                        // push the next point into the queue and update its distance
                        q.emplace(nxt_x, nxt_y);
                        d[nxt_x][nxt_y] = d[x][y] + 1;

                        // if the next point is water, update the answer
                        if(not grid[nxt_x][nxt_y]){
                            ans = max(ans, d[nxt_x][nxt_y]);
                        }
                    }
                }
            }
        }

        // if the answer is -1, it means that there is no water point or no land point
        return ans;
    }
};
