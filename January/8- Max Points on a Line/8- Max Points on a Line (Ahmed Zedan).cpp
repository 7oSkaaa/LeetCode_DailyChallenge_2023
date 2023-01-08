//author: Ahmed Zedan
class Solution {
public:
    // function to get slope between to point
    double slope(double x1 , double y1 , double x2 , double y2){
        if(x2==x1) return INT_MAX ; 
        return (y2-y1) / (x2-x1) ; 
    }
    /*
    hint:
        if have three point (x , y , z)
        if slope(xy) = slope(xz) then x , y and z on the same straight line
    */
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2) return points.size() ; // if number of points<=2 then points on the same straight line
        int mx = INT_MIN ;  
        for(int i=0 ; i<points.size() ; i++){
            map<double,int>mp ;  // freq of the slope to know how many points on the same straight line have this slope 
            for(int j=0 ; j<points.size() ; j++){
                if(i!=j){
                    double x = slope(points[i][0],points[i][1],points[j][0],points[j][1]) ; 
                    mp[x]++ ; 
                    mx = max(mx,mp[x]) ; 
                } 
            }
        }
        return mx+1 ; // plus one to calculate first point in straight line
    }
};
