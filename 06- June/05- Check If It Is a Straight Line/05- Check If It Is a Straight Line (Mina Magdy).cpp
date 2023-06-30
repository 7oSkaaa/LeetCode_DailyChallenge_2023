// Author: Mina Magdy

class Solution {
public:
    // Function to check if the given points form a straight line
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Calculate the differences in y and x coordinates between the first two points
        int dy = coordinates[0][1] - coordinates[1][1];
        int dx = coordinates[0][0] - coordinates[1][0];
        
        // Iterate over the remaining points starting from index 2
        for (int i = 2; i < coordinates.size(); i++) {
            // Calculate the differences in y and x coordinates between the first point and the current point
            int delta_y = coordinates[0][1] - coordinates[i][1];
            int delta_x = coordinates[0][0] - coordinates[i][0];
            
            // Check if the differences in y and x coordinates are proportional to the differences of the first two points
            if (delta_y * dx != delta_x * dy)
                return false; // If not proportional, the points do not form a straight line
        }
        
        return true; // All points are on the same line
    }
};
