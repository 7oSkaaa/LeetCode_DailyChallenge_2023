// Author: Ahmed Hossam

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // add the new interval in the vector of intervals
        intervals.push_back(newInterval);

        // sort the interval to make the new one in the right place
        sort(intervals.begin(), intervals.end());

        // make new vector to insert the marged_intervals in it
        vector < vector < int > > merged;

        // add the first interval to the vector
        merged.push_back(intervals.front());

        for(int i = 1; i < intervals.size(); i++){
            /*
                if the current interval less than or equal the last last time that convered with the merged interval 
                so i will take the max end of the two intervals
                otherwise i will start new interval by pushing it to the merged intervals vector
            */
            if(intervals[i].front() <= merged.back().back()) 
                merged.back().back() = max(merged.back().back(), intervals[i].back());
            else 
                merged.push_back(intervals[i]);
        }

        // the merged vectors
        return merged;
    }
};
