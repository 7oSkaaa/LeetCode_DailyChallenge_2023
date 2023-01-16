// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // push the new interval to the intervals vector
        intervals.push_back(newInterval);
        // sort the intervals vector
        sort(intervals.begin(), intervals.end());

        // initialize the ans vector and the current interval
        vector<vector<int>> ans;
        vector<int> cur = intervals[0];

        // loop over the intervals vector
        // merge the intervals if they overlap
        for(int i = 0; i < intervals.size(); i++){
            // if the current interval doesn't overlap with the next interval
            // push the current interval to the ans vector
            if(intervals[i][0] > cur[1]){
                ans.push_back(cur);
                cur = intervals[i];
            }else
                // if the current interval overlaps with the next interval
                // update the current interval to be the union of the two intervals
                cur[1] = max(intervals[i][1], cur[1]);
        }

        // push the last interval to the ans vector
        ans.push_back(cur);
        return ans;
    }
};
