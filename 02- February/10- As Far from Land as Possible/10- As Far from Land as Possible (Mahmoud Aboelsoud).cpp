// Author: Mahmoud Aboelsoud

class Solution {
public:
    // directions vectors
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    // check if the new position is valid
    bool valid(int&x, int&y, int&n){
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    // the idea is to start from all the lands and go to the nearest water
    // and then go to the nearest water from the previous water
    // and so on until we reach the end
    // the number of steps is the answer

    int maxDistance(vector<vector<int>>& grid) {
        // get the size of the grid
        int n = grid.size();
        // queue to store the lands
        queue<pair<int,int>> q;

        // push all the lands to the queue
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({i, j});
            }
        }

        // if there is no land or no water return -1
        if(q.size() == 0 || q.size() == n * n) return -1;

        // the number of steps from the lands to the water we start it with -1 because we start from the lands
        int cnt = -1;

        // bfs
        while(q.size()){
            int k = q.size();
            // increase the number of steps
            cnt++;
            // go to the nearest water from the current lands
            while(k--){
                // get the current land
                auto [x, y] = q.front();
                q.pop();

                // visit all the 4 directions
                for(int i = 0; i < 4; i++){
                    int nwx = x + dx[i];
                    int nwy = y + dy[i];
                    
                    // if the new position is valid and it's water then push it to the queue
                    if(valid(nwx, nwy, n) && grid[nwx][nwy] == 0){
                        // mark it as visited
                        grid[nwx][nwy] = 1;
                        // push it to the queue
                        q.push({nwx, nwy});
                    }
                }
            }
        }
        // return the number of steps
        return cnt;
    }
};
