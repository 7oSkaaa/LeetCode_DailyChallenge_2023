//Author: Omar Salem
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(),points.end());
        int left = points[0][0], right = points[0][1];
        for(int i = 1; i < points.size() ;i++){
            
            //checking if the current balloon can be hit by the current arrow
            if(points[i][0]<=right && points[i][1]>=left)
            {
                left = max(points[i][0],left);
                right = min(points[i][1],right);
            }
            else
            {
                //if not then increasing the arrow number and 
                //setting the current balloon range as new range
                ans++;
                left = points[i][0], right = points[i][1];
            }
        }
        return ans;
    }
    /*
    1 2
    2 3
    3 4
    4 5
    */
};