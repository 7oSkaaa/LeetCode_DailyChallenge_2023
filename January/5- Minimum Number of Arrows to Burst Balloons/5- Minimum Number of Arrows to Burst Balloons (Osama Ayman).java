// Author: Osama Ayman

class Solution {
    public int findMinArrowShots(int[][] points) {
        //sort ascendingly by start value
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        // set the limit of the arrow to the X-end to allow for the maximum
        // range to burst other ballons
        int res = 1, end = points[0][1];
        for(int i=1; i<points.length; i++){
            // if the next balloon has starting point greater than the end, then we need another arrow.
            if( points[i][0] > end ) {
                res++;
                end = points[i][1];
            }
            
            // As we want to get the common point to all, update end with the min val.
            end = Math.min(end, points[i][1]);
            
            
        }
        return res;
    }
}