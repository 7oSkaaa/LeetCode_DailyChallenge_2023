// Author: Reham Atta

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        // to Know if the points in the same line or not we found the slope 
        // and the points with the same slope are on the same line 
        // for each point and the next we find slope
        // return the number of points that have the same slope 

        int n = points.size();
        if(n <= 2) return n;
        int value=0;
        float slope = 0;
        for(int i = 0; i < n; i++){
            map <float,int> mp;
            float x1 = points[i][0] , y1 = points[i][1];
            for(int j = i + 1 ; j < n ; j++){
                float x2 = points[j][0] , y2 = points[j][1];
                if(x1 != x2) slope = (y2 - y1) / (x2 - x1); 
                if(x1 == x2) slope = INT_MAX;
                mp[slope]++; 
                value = max(value , mp[slope]);
            }
        }
        return value +1;  
    }
};