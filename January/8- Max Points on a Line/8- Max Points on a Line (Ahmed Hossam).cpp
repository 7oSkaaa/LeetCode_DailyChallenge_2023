// Author: Ahmed Hossam

class Solution {
public:

    // Check if three points in the same line
    bool is_same_line(int x1, int y1, int x2, int y2, int x3, int y3){
        return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
    }

    int maxPoints(vector<vector<int>>& points) {
        // inital variables
        int n = points.size(), max_points = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // calculate the number of points that laying in the same line with point[i] and point[j]
                int curr_points = 2;
                for(int k = j + 1; k < n; k++)
                    curr_points += is_same_line(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                
                // update max_points with the maximum that i got.
                max_points = max(max_points, curr_points);
            }
        }

        // maximum points laying in the same line
        return max_points;
    }
};
