// Author: Ahmed Hossam

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the points priority to x_start after that shortest x_end
        sort(points.begin(), points.end(), [&](vector < int >& a, vector < int >& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        int arrows = 1, n = points.size(), farthest_point = points[0][1];
        
        for(int i = 1; i < n; i++){
            
            // start new coverage area with new arrow
            if(points[i][0] > farthest_point)
                farthest_point = points[i][1], arrows++;
            
            // make the farthest points minimum to be the point the cover all previous points with same arrow
            farthest_point = min(farthest_point, points[i][1]);
        }

        // number of arrows;
        return arrows;
    }
};
