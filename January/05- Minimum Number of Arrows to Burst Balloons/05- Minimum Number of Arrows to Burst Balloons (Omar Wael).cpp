// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end());
        // interval that will shoot first arrow on it
        int start=points[0][0],end=points[0][1];
        for(int i=1;i<points.size();i++){
            // if this ballon in the interval
            if(start<=points[i][0] && end>=points[i][0]){
                // update the interval
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }else{
                // shoot new arrow 
                ans++;
                // create new interval
                start=points[i][0];
                end=points[i][1];
            }
        }
        return ans;
    }
};