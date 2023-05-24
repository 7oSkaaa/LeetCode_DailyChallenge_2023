// Author: Ahmed Gamal

// this is a simple implementation problem
// we can just simulate the process of spiral order
// to simulate the process we need to know the current direction and the next direction
// we can use dx and dy arrays to get the next direction
// we can use a vis array to mark the visited cells (not to visit them again)
// we can use a valid function to check if the next cell is valid or not

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // n: number of rows
        // m: number of columns
        // vis: visited array
        const int n = int(matrix.size()), m = int(matrix.front().size());
        array<array<bool, 10>, 10> vis{};

        // valid function
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 and i < n and j >= 0 and j < m and not vis[i][j];
        };

        // dx and dy arrays represent the directions in order (right, down, left, up)
        array dx {0, 1, 0, -1}, dy {1, 0, -1, 0};

        // ans: the answer
        vector<int> ans;

        // i, j: current cell
        // d: current direction
        // ok: flag to check if we can continue or not (initially true)
        int i = 0, j = 0, d = 0;
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

                // add the current cell to the answer
                ans.emplace_back(matrix[i][j]);

                // move to the next cell
                i += dx[d], j += dy[d];
            }

            // here, we are in a cell that we can't continue in the current direction (out of bounds or visited)
            // so, we need to go back to the previous cell and change the direction
            i -= dx[d], j -= dy[d];

            // the next direction is circular (right, down, left, up)
            d = (d + 1) % 4;
            i += dx[d], j += dy[d];
        }

        return ans;
    }
};