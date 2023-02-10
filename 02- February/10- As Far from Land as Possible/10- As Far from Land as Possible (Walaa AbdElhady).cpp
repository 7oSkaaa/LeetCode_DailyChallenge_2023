// Author: Walaa AbdElhady

class Solution {
private:
    // to check if we visit this cell before or not
    bool vis[101][101];
    // 4 direction to loop on them
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //BFS from each land cell (1) to calculate the minimum distance(shortest path) from each cell of them to water cells (0)
        queue<pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({ i,j });
                }
            }
        }
        //if there is no water cell return -1
        if (q.size() == n * m)return -1;
        int dis = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int>p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (int i = 0; i < 4; i++) {
                    int nexti = x + dx[i];
                    int nextj = y + dy[i];
                    // if this cell is valid and it contains water (0) and we did not visit it before => push this position
                    if (nexti < n && nexti >= 0 && nextj < m && nextj >= 0 && grid[nexti][nextj] == 0 && !vis[nexti][nextj]) {
                        q.push({ nexti,nextj });
                        vis[nexti][nextj] = true;
                    }
                }
            }// after finish each level in tree increase distance by one
            dis++;
        }
        return dis - 1;
    }
};