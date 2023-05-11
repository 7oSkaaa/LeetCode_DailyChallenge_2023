// author : Omar Sanad

// declare two arrays for the directions sorted as desired in the problem -> ↓ <- ↑
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    // declare the answer where we will store the answer
    vector<vector<int>> matrix;

    // delcare the dimentions of the grid
    int n;

    // declare a valid function to check whether the given position if both inside the grid and have not been visited before
    bool valid(int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < n and not matrix[x][y];
    }

    // the recurrsion function
    // we have three parameters: x, y are the position of the current cell
    // id is the index of current direction we are taking in the two arrays declared dx, dy declared in line 4, 5
    void Rec(int x, int y, int id, int currValue) {
        // add the value of the current cell in the answer vector
        matrix[x][y] = currValue;

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
        Rec(x + dx[id], y + dy[id], id, currValue + 1);
    }

    vector<vector<int>> generateMatrix(int n) {

        matrix.assign(n, vector < int > (n, 0));
        this -> n = n;

        // start the recurrsion function
        Rec(0, 0, 0, 1);

        // return the answer matrix
        return matrix;
    }
};
