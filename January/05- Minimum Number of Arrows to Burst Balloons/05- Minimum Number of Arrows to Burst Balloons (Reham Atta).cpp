//Author: Reham Atta

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {       
        if(points.size() == 0) return 0;

        // need one arrow at least to burst balloons
        int cnt = 1;

        // sort vector
        sort(points.begin(),points.end());

        int last = points[0][1];
        for(int i=1;i<points.size();i++){

        // if we found a first point greater than last point, then increase cnt and update last point 
            if(points[i][0] > last) {
              cnt++;
              last = points[i][1];
            }
        // else we will have minimum of end point stored
            else {
                last = min(last,points[i][1]);
            }
        }
        return cnt;
    }
};


/*
  1------6
     2------8
          7------12 
              10-----16
*/