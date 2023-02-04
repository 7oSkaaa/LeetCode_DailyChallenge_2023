// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            // if current interval before new inerval
            if(newInterval[0]>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            // if new inerval before current interval
            else if(newInterval[1]<intervals[i][0]){
                ans.push_back(newInterval);
                newInterval[0]=intervals[i][0];
                newInterval[1]=intervals[i][1];
            }
            // current interval and new inerval are in the same renge
            else {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        // add the updated new inerval
        ans.push_back(newInterval);
        return ans;
    }
};