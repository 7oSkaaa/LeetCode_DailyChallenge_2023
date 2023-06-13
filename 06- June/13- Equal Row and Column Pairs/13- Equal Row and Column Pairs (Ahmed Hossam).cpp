// Author: Ahmed Hossam

class Solution {
public:
    // This function calculates the number of equal pairs in a 2D grid
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid (assuming it's a square grid)
        int equal_pairs = 0; // Initialize the count of equal pairs

        map < vector < int >, int > freq; // Create a map to store the frequency of each row vector

        // Count the frequency of each row vector in the grid
        for(int row = 0; row < n; row++)
            freq[grid[row]]++;

        // Iterate through each column in the grid
        for(int col = 0; col < n; col++) {
            vector<int> curr_col(n); // Create a temporary vector to store the current column

            // Extract the elements of the current column from each row
            for(int row = 0; row < n; row++)
                curr_col[row] =  grid[row][col];

            // Add the frequency of the current column vector to the count of equal pairs
            equal_pairs += freq[curr_col];
        }

        return equal_pairs; // Return the total count of equal pairs
    }
};
