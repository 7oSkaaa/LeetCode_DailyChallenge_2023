// Author: Ahmed Hossam

class Solution {
public:
        
    // Declare a vector to store the elements of the matrix in spiral order.
    vector<int> spiral;

    // Recursive function to traverse the matrix in spiral order and store the elements in the spiral vector.
    void getSprial(vector<vector<int>>& grid, int i, int j, int m, int n) {

        // Base case: if i >= m or j >= n, return from the function.
        if (i >= m or j >= n)
            return;

        // Traverse the first row from j to n-1 and push the elements into the spiral vector.
        for (int p = j; p < n; p++)
            spiral.push_back(grid[i][p]);

        // Traverse the last column from i+1 to m-1 and push the elements into the spiral vector.
        for (int p = i + 1; p < m; p++)
            spiral.push_back(grid[p][n - 1]);

        // Traverse the last row from n-2 to j and push the elements into the spiral vector.
        if ((m - 1) != i)
            for (int p = n - 2; p >= j; p--)
                spiral.push_back(grid[m - 1][p]);

        // Traverse the first column from m-2 to i+1 and push the elements into the spiral vector.
        if ((n - 1) != j)
            for (int p = m - 2; p > i; p--)
                spiral.push_back(grid[p][j]);

        // Recursive call to traverse the next inner matrix.
        getSprial(grid, i + 1, j + 1, m - 1, n - 1);
    }

    // Function to return the elements of the matrix in spiral order.
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // Call the recursive function getSprial with the initial parameters.
        getSprial(matrix, 0, 0, matrix.size(), matrix[0].size());

        // Return the spiral vector containing the elements of the matrix in spiral order.
        return spiral;
    }


};