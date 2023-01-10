// Author: Anwar Rizk

class Solution {
public:

    // Definition for a point.
    struct point {
        int x, y;
    };

    int maxPoints(vector<vector<int>>& points) {
        // variable to store the maximum number of points on a line
        // and the number of points
        int max_points = 1, n = points.size();
        for(int i = 0; i < n; i++)
        {
            // variable to store the maximum number of points on a line with the point i
            int maxi = 0;
            // map to store the number of points on a line with the point i and the slope
            map < double, int > occ;
            // point i
            point p1 = {points[i][0], points[i][1]};
            for(int j = i + 1; j < n; j++)
            {
                // point j
                point p2 = {points[j][0], points[j][1]};
                // slope of the line with the point i and j (if the slope is infinity, we store 1e9)
                // we use double to avoid precision errors
                // we use the formula (y2 - y1) / (x2 - x1)
                double slope = (p1.x == p2.x ? 1e9 : double(p1.y - p2.y) / (p1.x - p2.x));
                // update the maximum number of points on a line with the point i
                maxi = max(maxi, ++occ[slope]);
            }
            // update the maximum number of points on a line with any point
            max_points = max(max_points, maxi + 1);
        }
        return max_points;
    }
};