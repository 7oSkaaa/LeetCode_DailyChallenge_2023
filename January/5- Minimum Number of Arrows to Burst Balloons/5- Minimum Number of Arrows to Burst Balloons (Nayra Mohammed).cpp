//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
  
  //Main Idea is knowing how many points we have after applying intersection between the orginal.
  
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());/*first we sort the points in asscending order according to X_start,
                                            in case of similarity then we sort it according to X_end
                                           */
        pair<int,int>curr = {points[0][0],points[0][1]}; //our base point
        int ans = 1; // base answer

        for(int i=1;i<sz(points);i++)
        { 
            if(curr.second<points[i][0]) /* if our base point's end is less than the following point's start,
                                            there is no intersection. switch the base point to new point and increase the answer
                                         */ 
                curr = {points[i][0],points[i][1]},ans++;
            else
                curr.second = min(curr.second,points[i][1]); // in case of intersection we need to take the minimum end! 
        }
     
        return ans;  
    }
};
