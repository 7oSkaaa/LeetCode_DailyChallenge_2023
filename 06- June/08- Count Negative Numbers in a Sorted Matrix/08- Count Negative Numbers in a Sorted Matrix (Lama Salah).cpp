// Author: Lama Salah

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0; // Count of negative numbers.
        
        // Iterate over each row of the grid.
        for (int row = 0; row < grid.size(); row++) {
            int left = 0; // Left pointer.
            int right = grid[row].size() - 1; // Right pointer.
            int best = -1; // Index of the maximum negative number.
            
            // Binary search to find the maximum negative number in the row.
            while (left <= right) {
                int mid = left + (right - left) / 2; // Calculate the middle index.
                
                // If the value at the middle index is less than or equal to -1,
                // update the right pointer and set the best index to the current middle index.
                // If not, move the left pointer to the right of the middle index.
                grid[row][mid] <= -1? right = mid - 1,  best = mid : left = mid + 1;
            }

            // If a negative number was found in the row,
            // add the count of negative numbers to the total count.
            if (~best) {
                negativeCount += grid[row].size() - best;
            }
        }

        // Return all negative numbers in the grid.
        return negativeCount;
    }
};