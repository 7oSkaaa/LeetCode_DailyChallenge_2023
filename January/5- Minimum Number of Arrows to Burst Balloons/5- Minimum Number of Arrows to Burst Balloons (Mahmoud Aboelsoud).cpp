class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the points
        sort(points.begin(), points.end());
        
        //initalize the end_point with the end point of the first balloon and the ans with 1 arrow to brust this balloon
        int end_point = points[0][1], ans = 1;
        
        // loop on the sorted points
        for(auto&i : points){
            
            // check if the start of the current balloon cannot be included in our current arrow range
            if(i[0] > end_point)
                // start a new range with new arrow for the current 
                ans++, end_point = i[1];

            // imagine you have 2 ballons at points (1, 10) and (2, 6) your first range to shoot an arrow at the beginning will be from 1 to 10,
            // you want to increase the number of brusted balloons with one arrow so you need to brust the second balloon with the same arrow as the first one
            // but saying that your range is from 1 to 10 isn't true in that case because you can't brust the second balloon if you shooted the arrow in points
            // from [1 to 2) or from (6 to 10] so you need to update your range to be from [2 to 6] so we always take the min end point of the balloons that
            // would be brusted by the current arrow. you don't want to keep track of the starting point because our points array is sorted so it's always 
            // updated to the max start point of the balloons that would be brusted by the current arrow.
            end_point = min(end_point, i[1]);
        }
        
        return ans;
    }
};