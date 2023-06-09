// Author: Ahmed Hossam

class Solution {
public:
    
    int countNegatives(vector<vector<int>>& grid) {
        // Get the number of rows in the grid
        int n = grid.size();
        
        // Initialize a counter variable to store the count of negative numbers
        int cnt = 0;
        
        // Iterate over each row in the grid
        for(int i = 0; i < n; i++) {
            // Find the position of the first element greater than -1 (negative number)
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            
            // Calculate the count of negative numbers in the current row
            int rowCnt = it - grid[i].rbegin();
            
            // Add the count of negative numbers in the current row to the total count
            cnt += rowCnt;
        }
        
        // Return the total count of negative numbers in the grid
        return cnt;
    }

};
