// author : Omar Sanad
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        // declare a variable sum to store the answer,
        // also declare n where the dimentions of the matrix is n * n
        int sum = 0, n = mat.size();

        // iterate over every cell in the matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // i == j : this cell is at the primary diagonal
                // i + j == n - 1 : this cell is at the secondary diagonal
                if (i == j or i + j == n - 1)
                    sum += mat[i][j];
        
        // return the answer to the problem
        return sum;
    }
};
