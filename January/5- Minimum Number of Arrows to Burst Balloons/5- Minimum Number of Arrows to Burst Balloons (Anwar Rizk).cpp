// Author: Anwar Rizk

/*
    To solve this problem, we can sort the array of points by their start position,
    and then iterate through the sorted array. For each balloon, we can check whether
    it can be burst by the previous arrow, or if we need to shoot a new arrow for it.
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        // We need at least one arrow
        int arrows = 1;
        // The previous arrow will be at the end of the first balloon
        int prev = points[0][1];
        for(auto& point : points){
            // If the current balloon's start position is greater than the previous arrow's end position,
            // then we need to shoot a new arrow for it
            // Otherwise, we can use the previous arrow to burst the current balloon
            // We also need to update the previous arrow's end position to be the minimum of the previous
            // arrow's end position and the current balloon's end position
            if(point[0] > prev){
                arrows++;
                prev = point[1];
            }
            prev = min(prev, point[1]);
        }
        return arrows;
    }
};

/* 

Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2

    After sorting the array of points by their start position, we get:
    [[1,6],[2,8],[7,12],[10,16]]

    on the first iteration, we shoot an arrow at the end of the first balloon, which is 6
    on the second iteration, we can use the previous arrow to burst the second balloon, at 2 < 6
    on the third iteration, we shoot an arrow at the end of the third balloon, which is 12
    on the fourth iteration, we can use the previous arrow to burst the fourth balloon, at 10 < 12

    So, we need 2 arrows to burst all the balloons

*/