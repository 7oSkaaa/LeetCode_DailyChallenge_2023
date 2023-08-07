// Author: Ahmed Hossam

class Solution {
public:
    int BS_2D(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, best = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            // If target is greater or equal, move search to the right half of the column
            // Otherwise, move to the left half and update the potential "best" row index
            (matrix[m][0] <= target ? l = m + 1, best = m : r = m - 1);
        }
        return best;
    }
    
    bool BS_1D(vector< int >& matrix, int target) {
        int l = 0, r = matrix.size() - 1, best = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            // If target is greater or equal, move search to the right half of the vector
            // Otherwise, move to the left half and update the potential "best" index
            (matrix[m] <= target ? l = m + 1, best = m : r = m - 1);
        }
        // Check if target was found at the best index
        return (best == -1 || matrix[best] != target ? false : true);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find the potential row index using binary search along the first column
        int row_idx = BS_2D(matrix, target);
        // If no suitable row index is found, target cannot be in the matrix
        if(row_idx == -1) return false;
        // Search for the target in the identified row using binary search in 1D vector
        return BS_1D(matrix[row_idx], target);
    }
};
