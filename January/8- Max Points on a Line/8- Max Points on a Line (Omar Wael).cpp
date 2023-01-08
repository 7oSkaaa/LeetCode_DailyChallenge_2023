// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        for(int i=0;i<points.size();i++){
            map<double,int>slope;
            for(int j=0;j<points.size();j++){
                // if i!=j calculate the slope between this two points 
                if(i!=j){
                    double s=(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    slope[s]++;
                }
            }
            // search on the map to find maximum frequently slope
            for(auto it:slope){
                ans=max(ans,it.second +1);
            }
        }
        return ans;
    }
};