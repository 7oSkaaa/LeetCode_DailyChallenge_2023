// Author: Ahmed Gamal


// this is another simple implementation problem, but this time we need to fill the matrix
// we can just simulate the process of spiral order like the previous problem with some changes

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // vis: visited array
        array<array<bool, 20>, 20> vis{};

        // valid function
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 and i < n and j >= 0 and j < n and not vis[i][j];
        };

        // dx and dy arrays represent the directions in order (right, down, left, up)
        array dx {0, 1, 0, -1}, dy {1, 0, -1, 0};


        // i, j: current cell
        // d: current direction
        // num: current number
        // ok: flag to check if we can continue or not (initially true)
        // ans: the answer matrix
        int i = 0, j = 0, d = 0;
        int num = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        bool ok = true;

        // while we can continue
        while(ok) {
            // assume that we can't continue
            ok = false;

            // while we can continue in the current direction
            while(valid(i, j)) {
                // we can continue
                ok = true;

                // mark the current cell as visited
                vis[i][j] = true;

                // add the current number to the current cell
                ans[i][j] = num++;

                // move to the next cell
                i += dx[d], j += dy[d];
            }

            // here, we are in a cell that we can't continue in the current direction (out of bounds or visited)
            i -= dx[d], j -= dy[d];

            // change the direction
            d = (d + 1) % 4;

            // move to the next cell
            i += dx[d], j += dy[d];
        }

        return ans;
    }
};