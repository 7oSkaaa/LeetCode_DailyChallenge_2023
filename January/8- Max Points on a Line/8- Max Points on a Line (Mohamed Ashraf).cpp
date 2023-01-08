//Author: Mohamed Ashraf

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int sz = points.size() , mx = 1;
        for(int i=0; i<sz; i++){
            // Reset the map  automatic
            map<double,int> lines;
            for(int j=0; j<sz; j++){
                if(i==j)
                    continue;
                double x = points[j][0] - points[i][0];
                double y = points[j][1] - points[i][1];
                double z = x/y;
                lines[z]++;
                // Update the maximum number of points on this straight line.
                mx = max(mx , lines[z]+1);
            }
        }
        return mx;
    }
};