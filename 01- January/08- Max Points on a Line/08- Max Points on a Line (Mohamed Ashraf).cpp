//Author: Mohamed Ashraf

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // inital variables
        int sz = points.size() , mx = 1;
        // loop for all points
        for(int i=0; i<sz; i++){
            // Map to store the number of lines and reset automatic with a new Point.
            map<double,int> lines;
            // Calculate the slope of the line formed by point[i] and every other point.
            for(int j=0; j<sz; j++){
                if(i==j)
                    continue;   // Skip it if same point.
                double x = points[j][0] - points[i][0];
                double y = points[j][1] - points[i][1];
                double z = x/y;
                lines[z]++; // Increment the count for this slope in the map
                // Update the maximum number of points on  the same straight line.
                mx = max(mx , lines[z]+1);  // +1 because we need to count  point[i]
            }
        }
        return mx;
    }
};
