// Author: Mohamed Ashraf

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort vector points
        sort(points.begin() , points.end());
        int x = points[0][1], n = points.size(), ans = 1;   // Initial variable (x) start with minimum point.
        for(int i = 1; i < n; i++){
            // check if arrow out of the range
            if(points[i][0] > x) 
                x = points[i][1], ans++;    // Change the value of x and increase ans one and start A new range
            x = min(x , points[i][1]);      // Update x with the min value.
        }
        return ans;
    }
};
