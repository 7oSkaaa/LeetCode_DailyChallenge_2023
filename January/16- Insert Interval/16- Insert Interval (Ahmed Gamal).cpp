// Author: Ahmed Gamal

class Solution {
public:

    // we want to insert the new interval in the intervals array so that the intervals array is still sorted and non-overlapping
    // we can do this by inserting the new interval in the intervals array and then sorting the intervals array to put the new interval in the correct position
    // then we can merge the intervals in the intervals array to make it non-overlapping
    // this reduces the problem to merging the intervals in the intervals array (simple problem)


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // insert the new interval in the intervals array
        intervals.emplace_back(newInterval);
        // sort the intervals array
        sort(intervals.begin(), intervals.end());

        // merge the intervals in the intervals array
        // the current start and end of the merged interval is the first interval in the intervals array (initially)
        int st = intervals.front().front(), ed = intervals.front().back();
        // the number of intervals in the intervals array currently
        const int n = int(intervals.size());

        // iterate over the intervals in the intervals array
        for(int i = 0; i < n; i++){
            // if the current interval doesn't overlap with the merged interval
            if(intervals[i].front() > ed){
                // add the merged interval to the intervals array
                intervals.push_back({st, ed});
                // set the start and end of the merged interval to the current interval
                st = intervals[i].front();
                ed = intervals[i].back();
            }else{
                // if the current interval overlaps with the merged interval, then we want to merge the current interval with the merged interval
                ed = max(ed, intervals[i].back());
            }
        }
        // add the last merged interval to the intervals array
        intervals.push_back({st, ed});
        // erase the first n intervals in the intervals array (the intervals of the input)
        // after this, the intervals array will contain the merged intervals only (the last n intervals in the intervals array)
        intervals.erase(intervals.begin(), intervals.begin() + n);

        // return the intervals array
        return intervals;
    }
};