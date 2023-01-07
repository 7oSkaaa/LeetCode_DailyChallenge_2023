// Author: Eileanora

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int arrows = 1;
        //treat ballons the same as intervals and shoot ballons with that share the same boundries with an arrow
        int start = points[0][0];  //mark start and end of my interval
        int end = points[0][1];
        for(int i = 0; i < points.size(); i++)
        {
            if(start < points[i][0] && end < points[i][0]) //if it doesn't belong to the interval
            {
                start = points[i][0];
                end = points[i][1];
                arrows++;
                //shoot the arrow and start a new interval starting with this ballon
                continue;
            }
            //update my interval to match tha smallest ballon in it
            start = max(start , points[i][0]);
            end = min(end , points[i][1]);
        }
        return arrows; 
    }
};
