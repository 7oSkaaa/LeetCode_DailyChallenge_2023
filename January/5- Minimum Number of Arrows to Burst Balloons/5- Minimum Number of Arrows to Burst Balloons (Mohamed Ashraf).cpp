// Author: Mohamed Ashraf

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int x = points[0][1], n = points.size(), ans = 1;
        for(int i = 1; i < n; i++){
            if(points[i][0] > x) x = points[i][1], ans++;
            x = min(x , points[i][1]);
        }
        return ans;
    }
};