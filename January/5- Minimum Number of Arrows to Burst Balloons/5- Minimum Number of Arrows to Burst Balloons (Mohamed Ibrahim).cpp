// Author: Mohamed Ibrahim

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    // Sort the balloons by their right x-coordinates.
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    // Initialize the position of the last arrow to be the right 
    //x-coordinate of the first balloon.
    int arrowPos = points[0][1];
    int arrowCnt = 1;
    for (int i = 1; i < points.size(); i++) {
        // If the position of the last arrow is to the left of the left x-coordinate of the current balloon,
        // we need to shoot another arrow.
        if (arrowPos >= points[i][0]) {
            continue;
        }
        arrowCnt++;
        // Update the position of the last arrow to be the right x-coordinate of the current balloon.
        arrowPos = points[i][1];
    }
    // Return the number of arrows that were shot.
    return arrowCnt; 
    }
};