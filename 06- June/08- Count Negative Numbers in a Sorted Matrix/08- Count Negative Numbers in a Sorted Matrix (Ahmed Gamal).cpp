// Author: Ahmed Gamal

// for this problem, we will loop over all rows in the grid and calculate the number of negative numbers in it
// we will do these operations in amortized O(n + m) time complexity, where n is the number of rows and m is the number of columns
// to achieve this, we will use the fact that the grid is sorted in non-increasing order in each row and column

// that means that if we find a negative number in a row, then all the numbers to the right of it are negative
// and all the numbers to the down of it are negative as well
// so for each row, we will find the first negative number in it, and then we will add the number of negative numbers in it to the answer
// and for the next row, we will start searching from the last column that we found a negative number in it in the previous row

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // j: the last column that we found a negative number in it
        // ans: the answer
        int j = grid[0].size() - 1, ans = 0;

        // loop over all rows
        for(int i = 0; i < grid.size(); i++) {
            // find the first non-negative number in the current row
            while(~j and grid[i][j] < 0) {
                j--;
            }

            // add the number of negative numbers in the current row to the answer (subtract 1 because we counted the first non-negative number in the current row)
            ans += grid[0].size() - j - 1;
        }

        return ans;
    }
};