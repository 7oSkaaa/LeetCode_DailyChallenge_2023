// Author: Ahmed Gamal

// for this problem we can find if there is a path to cross the river using any graph traversal algorithm (bfs, dfs, ...)
// but here we need to find the last day where we can cross the river
// so we can use binary search to find the last day where we can cross the river

// to use binary search we need to find a function that returns true if we can cross the river on day x and false otherwise
// this function will be good(mid) where mid is the day that we are checking
// and inside this function we will use bfs to check if we can cross the river on day midd
// why bs?
// because if we can cross the river on day x then we can cross it on any day <= x
// and if we can't cross the river on day x then we can't cross it on any day >= x
// and we can see that the function good(x) is monotonic (if we can cross the river on day x then we can cross it on any day <= x)

// binary search will help us to reduce the time complexity by doing less bfs calls (we will do at most log(row * col) bfs calls)

// mid: the day that we are checking, so we will add the first mid cells to the invalid cells
// and since we can start at any cell in the first row we will add all the cells in the first row to the queue unless they are invalid
// and then we will do multisource bfs from the cells in the first row and check if any of them can reach the last row

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // dx, dy: directions (right, left, down, up)
        vector<int> dx {0, 0, 1, -1}, dy {1, -1, 0, 0};

        // left, right: the range of the binary search (the answer will be in [left, right))
        int left = 0, right = row * col + 1;        

        // valid: check if the indices are valid
        auto valid = [&](int i, int j) -> bool {
            return i >= 1 and i <= row and j >= 1 and j <= col;
        };

        // good: check if we can cross the river on day mid
        auto good = [&](int mid) -> bool {
            // q: the queue that we will use in bfs
            // vis: the visited array
            // invalid: the invalid cells (the first mid cells covered by water)
            queue<pair<int, int>> q;
            vector vis(row + 1, vector(col + 1, false));
            auto invalid = vis;

            // add the first mid cells to the invalid cells
            for(int i = 0; i < mid; i++) {
                invalid[cells[i][0]][cells[i][1]] = true;
            }

            // add all the cells in the first row to the queue unless they are invalid
            for(int i = 1; i <= col; i++) {
                if(invalid[1][i]) {
                    continue;
                }
                q.emplace(1, i);
            }

            // multisource bfs
            while(not q.empty()) {
                // x, y: the current cell
                auto [x, y] = q.front();
                q.pop();

                // check the four directions
                for(int d = 0; d < 4; d++) {
                    // new_x, new_y: the new cell
                    int new_x = x + dx[d], new_y = y + dy[d];

                    // check if the new cell is valid and not visited and not covered by water
                    if(valid(new_x, new_y)) {
                        if(vis[new_x][new_y] or invalid[new_x][new_y]) {
                            continue;
                        }

                        // mark the new cell as visited and add it to the queue
                        vis[new_x][new_y] = true;
                        q.emplace(new_x, new_y);
                    }
                }
            }

            // check if any cell in the last row is visited
            for(int i = 1; i <= col; i++) {
                if(vis[row][i]) {
                    return true;
                }                
            }

            return false;
        };


        // binary search
        while(left < right - 1) {
            int mid = left - (left - right) / 2;

            if(good(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }
};