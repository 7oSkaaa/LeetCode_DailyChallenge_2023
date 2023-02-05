// Author: Ahmed Gamal

class Solution {
public:

    // here, I will just implement the algorithm described in the problem statement since it's not that complicated and the constraints are not that big
    // I will use a grid to store the characters in the zigzag pattern
    // then I will read the characters from the grid and add them to the answer string


    string convert(string s, int numRows) {
        // the largest number of rows possible will be numRows
        // the largest number of columns possible will be s.size()
        //  so the grid will be numRows x s.size() (plus some extra space)
        vector<vector<char>> grid(numRows, vector<char>(s.size() + 10));

        // idx will hold the index of the current character in s
        // x will hold the current row in the grid
        // y will hold the current column in the grid
        // all of them will start from 0
        int idx(0), x(0), y(0);

        // loop until we reach the end of s
        while(idx < s.size()){
            // we will first fill the grid from top to bottom (row by row using the same column)
            for(; idx < s.size() and x < numRows; x++){
                grid[x][y] = s[idx++];
            }

            // after the previous loop, x will be equal to numRows (out of bounds)
            // the next character will be in the next column (y + 1) and the row above the previous row (x - 2)
            x -= 2, y++;

            // we will then fill the grid from bottom to top (diagonally)
            // we will start from the row above the previous row (x - 1) and the next column (y + 1) and we will stop when we reach the first row (x == 0) or the end of s
            // if numRows == 1, then X will be -1 and we will stop at the first row, so we will use max(x, 0) to make sure that x is not negative
            for(x = max(x, 0); idx < s.size() and x >= 0; x--, y++){
                grid[x][y] = s[idx++];
            }

            // after the previous loop, x will be -1 (out of bounds)
            // and y will be the next column (y + 1)
            // and the next character should be in the next row (x + 2) and the same column (y)
            x += 2, y--;
        }

        string ans;

        // read the characters from the grid and add them to the answer string
        for(auto& i : grid){
            for(auto& j : i){
                if(isalpha(j) or j == ',' or j == '.')
                    ans += j;
            }
        }

        return ans;
    }
};