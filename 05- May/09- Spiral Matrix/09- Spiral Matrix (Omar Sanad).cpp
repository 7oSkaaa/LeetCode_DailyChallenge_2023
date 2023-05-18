// author : Omar Sanad

// declare two arrays for the directions sorted as desired in the problem -> ↓ <- ↑
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    // declare the matrix in the class itself, to be able to use it anywhere in the class
    vector<vector<int>> matrix;

    // delcare the dimentions of the grid
    int n, m;

    // declare a visited array to use it in the recurrsion function
    vector < vector < bool > > vis;

    // declare a valid function to check whether the given position if both inside the grid and have not been visited before
    bool valid(int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m and not vis[x][y];
    }

    // declare a vector answer to store the answer to the problem
    vector < int > answer;

    // the recurrsion function
    // we have three parameters: x, y are the position of the current cell
    // id is the index of current direction we are taking in the two arrays declared dx, dy
    void Rec(int x, int y, int id) {
        // mark the current cell as visited, to avoid visiting it again
        vis[x][y] = true;
        // add the value of the current cell in the answer vector
        answer.emplace_back(matrix[x][y]);

        // check if the next position if we continued with the current directions is not valid,
        // then we should change our direction
        if (not valid(x + dx[id], y + dy[id])){
            
            // this way we are changing our direction to next one as desired in the problem
            id = (id + 1) % 4;

            // if after we changed the invalid direction, the cell still not valid
            // then we have iterated over all cells
            // its time to terminate the recurrsion
            if (not valid(x + dx[id], y + dy[id]))
                return;
        }

        // if there is still valid cells to be visited,
        // then visit these cells
        Rec(x + dx[id], y + dy[id], id);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // assign the matrix given as a paremter from the spiralOrder function to the matirx declared in the class itself
        this->matrix = matrix;

        // assign values of n and m
        n = matrix.size(), m = matrix[0].size();

        // assign the visited array
        vis.assign(n, vector<bool>(m, false));

        // start the recurrsion function
        Rec(0, 0, 0);

        // return the answer to the problem
        return answer;
    }
};
