// Author: Ahmed Hossam

class Solution {
public:
    // Function to calculate the sum of diagonals of a given matrix
    int diagonalSum(const vector<vector<int>>& mat) {
        // Get the size of the matrix and initialize the sum variable to zero
        int n = mat.size(), sum = 0;
        
        // Loop through each row of the matrix
        for(int i = 0; i < n; i++) {
            // Add the element at the ith row and ith column to the sum
            sum += mat[i][i];
            // Add the element at the ith row and (n-i-1)th column to the sum
            sum += mat[i][n - i - 1];
        }
        
        // If the size of the matrix is odd, subtract the middle element from the sum
        return sum - (n & 1 ? mat[n / 2][n / 2] : 0);
    }
};
