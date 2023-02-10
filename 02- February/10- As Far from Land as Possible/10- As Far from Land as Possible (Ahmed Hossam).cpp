// Author: Ahmed Hossam

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // vector contains the four direction to loop on them
        vector < pair < int, int > > dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // lets make bfs from each land cell to calculate the minimum distance from each cell of them to water cells
        vector < vector < int > > dist(n, vector < int > (m, 1e9));
        queue < pair < int, int > > bfs;

        // lets add land cells
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)
                    dist[i][j] = 0, bfs.push({i, j});

        // if there is no land cell
        if(bfs.empty())
            return -1;

        // check if valid cell to add it
        auto is_valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m && !grid[x][y];
        };

        while(!bfs.empty()){
            auto [x, y] = bfs.front();
            bfs.pop();

            for(auto& [dx, dy] : dir){
                int nx = x + dx, ny = y + dy;

                // if the new cell is valid and you can reach it with distance less than its distance so add it to the queue
                if(is_valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1)
                    dist[nx][ny] = dist[x][y] + 1, bfs.push({nx, ny});
            }
        }

        // loop over the distance 2D vector to get the maximum distance for each water cell
        int max_dist = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!grid[i][j])
                    max_dist = max(max_dist, dist[i][j]);

        return max_dist;
    }
};
