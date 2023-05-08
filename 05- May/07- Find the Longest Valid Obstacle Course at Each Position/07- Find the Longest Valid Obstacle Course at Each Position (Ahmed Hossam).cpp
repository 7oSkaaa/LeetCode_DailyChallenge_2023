// Author: Ahmed Hossam

class Solution {
public:
    vector < int > longestObstacleCourseAtEachPosition(const vector < int >& obstacles) {

        // Get the size of the vector of obstacles
        int n = obstacles.size();

        // Create two vectors: LIS (initialized to 1e9) and LOC (initialized to 0)
        vector < int > LIS(n, 1e9), LOC(n);

        // Loop through the obstacles vector
        for(int i = 0; i < n; i++){

            // Get the upper bound of the current obstacle in the LIS vector
            auto up = upper_bound(LIS.begin(), LIS.end(), obstacles[i]);

            // Set the value of LOC at the current position to (the index of the upper bound + 1)
            LOC[i] = (up - LIS.begin() + 1);

            // Update the LIS vector with the current obstacle value
            *up = obstacles[i];
        }

        // Return the LOC vector
        return LOC;
    }
};
