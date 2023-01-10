// author: Esraa Syam
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        double solpe = 0;
        int res = 0;
        for(int i = 0 ; i < points.size() ; i++){
            map < double , int > mp;
            double x1 = points[i][0] , y1 = points[i][1];
            for(int j = i + 1 ; j < points.size() ; j++){
                double x2 = points[j][0] , y2 = points[j][1];
                if(x1 == x2) solpe = INT_MAX; // because slope is infinity (any number divided by 0 == infinity)
                if(x1 != x2) solpe = (y2 - y1) / (x2 - x1); // get the slope of the line
                mp[solpe]++; // count the number of points that have the same slope
                res = max(res , mp[solpe]); // get the maximum number of points that have the same slope
            }
        }
        return res + 1; // +1 because we need to count the first point too
        
    }
};
/* 
the idea :
to get the maximum number of points that lie on the same straight line
we need to count the number of points that have the same slope
and get the maximum number of points that have the same slope
to get the slope of the line we use the formula (y2 - y1) / (x2 - x1)
but if the line is vertical (x1 == x2) then the slope is infinity (any number divided by 0 == infinity)
so we use INT_MAX to represent infinity
*/