//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;//here to store our intervals after adding the new and merging them togther
        
        intervals.push_back(newInterval);//add newinterval to the whole intervals
        
        sort(intervals.begin(),intervals.end());//sort it accordin' to their starting point
        
        ans.push_back(intervals[0]);//make the first interval as our base
        
        for(int i = 1;i < sz(intervals); i++)//iterate through the rest of intervals..
        {
          /*if the starting point of current (i th) interval is bigger than the ending point of our last added interval
            then , they arent overlaping so we push that interval and think of it as our current base interval
          */
            if(intervals[i][0] > ans.back()[1]) 
                ans.push_back(intervals[i]);
            else //otherwise, an overlaping exists.. so we updated current base ending point to the maximum ending point between current interval and current base.  
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);    /*we sorted the intervals so for sure current interval's starting point would be <= current base's
                                                                        starting point so there is no need to update our base 's starting point*/
        }

        return ans;
    }
};
