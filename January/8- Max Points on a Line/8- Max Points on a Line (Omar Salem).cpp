class Solution {
public:
    // Check the slope of the points
    bool slope(int x1 , int y1 , int x2 , int y2 , int x3 , int y3)
    {
        return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
    } 
    /*
        (y2 - y1) / (x2 - x1) = (y3 - y1) / (x3 -x1) 
    or  (y3 - y1) * (x2 - x1) = (y2 - y1) * (x3 -x1)
    */
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size() , Max_points = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ;j++){

                int cur_points = 2;
                
                for(int k = j+1; k < n ; k++){
                    cur_points += slope(points[i][0] , points[i][1] ,points[j][0] , points[j][1] ,points[k][0] , points[k][1]);
                }
                Max_points = max(Max_points, cur_points);

            }
        }
        return Max_points;
    }
};