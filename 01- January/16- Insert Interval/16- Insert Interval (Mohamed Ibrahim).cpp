//Author: Mohamed Ibrahim

class Solution {
public:
    // define the function insert which takes in two parameters, a vector of vectors of integers called intervals and a vector of integers called newInterval
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Create an empty vector called ans
        vector < vector < int > > ans; 
        // Add newInterval to the end of the intervals vector
        intervals.push_back(newInterval); 
        // Sort the intervals vector based on the start of the intervals
        sort(intervals.begin(), intervals.end());
        // Add the first interval of the intervals vector to the ans vector
        ans.push_back(intervals[0]);
        // Loop through the intervals vector starting at the second element
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the start of the current interval is less than or equal to the end of the last interval in the ans vector
            if (intervals[i][0] <= ans.back()[1]) { 
                // If so, update the end of the last interval in the ans vector to be the maximum of the end of the last interval in the ans vector and the end of the current interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            } else {
                // If not, add the current interval to the ans vector
                ans.push_back(intervals[i]);
            }
        }
        // Return the ans vector
        return ans;
    }
};
