// Author: Mohamed Amr
// Topics: Sorting, Greedy, Implementation
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the array of points (according to start points then according to end points);
        sort(points.begin(), points.end());

        // temp variable to update the latest range of available balloons (initially = to first point).
        pair<int,int> temp = {points[0][0], points[0][1]};

        // answer is stored in ans;
        int ans=1;

        // compare each point starting point to the end point of the previous point (temp variable).
        // if(starting point < ending point of the previous)
        //                  update the range of the balloons to the minimum window (greatest beginning and smallest ending) 
        // else
        // set the window to the current point && increment ans by one
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0] <= temp.second)
            {
                temp.first = max(temp.first, points[i][0]);
                temp.second = min(temp.second, points[i][1]);
            }
            else
            {
                temp = {points[i][0], points[i][1]};
                ans++;
            }
        }
        return ans;
    }
};