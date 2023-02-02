//author: Esraa Syam
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector < vector < int > > ans; 
        intervals.push_back(newInterval); 
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // if the current interval overlaps with the previous,
            // use the maximum of the current and previous right boundary to merge the intervals 
            // otherwise, just add the current interval to the result
            if (intervals[i][0] <= ans.back()[1]) { 
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); // merge the intervals
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
        
    }
};
/*
the first test case is [[1,3],[6,9]] and [2,5]
                                  ..................
        .....................
 ................
-1------2-------3------4-----5----6-----7-----8-----9-----10
we need to merge the intervals [1,3] and [2,5] to [1,5]
so we need to use the maximum of the right boundary of the two intervals
the answer is [[1,5],[6,9]]
*/
