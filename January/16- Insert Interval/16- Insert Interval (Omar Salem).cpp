//Author: Omar Salem ;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector< vector < int > > ans;
        for(auto &i:intervals){
            if(i[1]<newInterval[0])
                ans.push_back(i);
            else if(newInterval[1]<i[0]){
                ans.push_back(newInterval);
                newInterval = i;//updating the new interval
            }
    // the new interval is in the range of the other interval
            else{
                newInterval[0] = min(newInterval[0],i[0]);
                newInterval[1] = max(newInterval[1],i[1]);
            }    
        }
    //At the end after the loop just add the updated newIntervals
        ans.push_back(newInterval);
        return ans;
    }
};