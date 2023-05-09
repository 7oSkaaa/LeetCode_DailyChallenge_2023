// Author: Mahmoud Aboelsoud

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // we need to find the sum of the elements in the two diagonals
        // the primary diagonal is the elements where the row and column index are equal
        // the secondary diagonal is the elements where the row and column index sum is equal to the size of the matrix minus one
        // we need to be careful if the size of the matrix is odd we need to subtract the middle element from the sum
        // we can do that by checking if the size of the matrix is odd or even

        // n: the size of the matrix
        int n = mat.size();
        // sum: the sum of the elements in the two diagonals
        int sum = 0;
        // loop over the main diagonal and add the elements to the sum
        for(int i = 0; i < n; i++) sum += mat[i][i];
        // loop over the secondary diagonal and add the elements to the sum
        for(int i = 0, j = n - 1; i < n; i++, j--) sum += mat[i][j];

        // if the size of the matrix is odd we need to subtract the middle element from the sum
        if(n % 2) sum -= mat[n/2][n/2];

        // return the sum
        return sum;
    }
};
