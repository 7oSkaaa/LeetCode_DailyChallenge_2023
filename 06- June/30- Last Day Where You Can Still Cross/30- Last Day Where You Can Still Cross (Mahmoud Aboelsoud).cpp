// Author: Mahmoud Aboelsoud

// for this probelm we need to find the last day where we can go from the first row to the last row using only land cells
// we can use binary search to find the last day where we can do it
// we can use bfs to check if we can reach the last row without passing through first m water cells

class Solution {
public:
    // directions arrays
    int dx[4] = {0 , 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        // check if we can cross the river using the first m cells
        auto good = [&](int m){
            // create a matrix to represent the land
            vector<vector<int>> mat(row, vector<int> (col, 0));

            // mark the first m cells as water 
            for(int i = 0; i < m; i++)
                mat[cells[i][0] - 1][cells[i][1] - 1] = 1;

            // bfs queue
            queue<pair<int,int>> q;
            
            // push the land cells in the first row to the queue and mark them as visited
            for(int i = 0 ; i < col; i++){
                if(mat[0][i] == 0){
                    q.push({0, i});
                    mat[0][i] = 1;
                }
            }

            // bfs to check if we can reach the last row
            while(q.size()){
                auto [x, y] = q.front(); q.pop();
                
                // check the four directions
                for(int i = 0; i < 4; i++){
                    int nwx = x + dx[i], nwy = y + dy[i];
                    if(nwx >= 0 && nwx < row && nwy >= 0 && nwy < col && mat[nwx][nwy] != 1){
                        // if we reach the last row return 1
                        if(nwx == row - 1) return 1;
                        // push the cell to the queue and mark it as visited
                        q.push({nwx, nwy});
                        mat[nwx][nwy] = 1;
                    }
                }
            }

            // if we can't reach the last row return 0
            return 0;
        };

        // binary search to find the last day where we can cross the river
        int l = 0, r = cells.size(), best = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(good(m)) best = m, l = m + 1;
            else r = m - 1;
        }

        // return the last day where we can cross the river
        return best;
    }
};
