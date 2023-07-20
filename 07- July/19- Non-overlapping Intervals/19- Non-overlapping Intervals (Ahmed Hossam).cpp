// Author: Ahmed Hossam

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals based on their start times in ascending order
        sort(intervals.begin(), intervals.end());
        
        // Initialize a variable to store the count of erased intervals
        int erased_intervals = 0;
        
        // Initialize a variable to keep track of the end time of the previous interval
        int previous_end = intervals[0][1];
        
        // Loop through the intervals starting from the second interval (index 1)
        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the previous one
            if (intervals[i][0] < previous_end) {
                // Increment the erased_intervals count, as we need to erase the current interval
                erased_intervals++;
                
                // Update the previous_end to the minimum of the current interval's end time and the previous_end
                previous_end = min(previous_end, intervals[i][1]);
            } else {
                // If the current interval does not overlap with the previous one, update the previous_end
                previous_end = intervals[i][1];
            }
        }
        
        // Return the count of erased intervals
        return erased_intervals;
    }
};
