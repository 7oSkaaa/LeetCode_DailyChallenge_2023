// Author: Ahmed Gamal

/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    // to solve this problem and find the minimum number of arrows required to burst all balloons,
    // we need to throw an arrow at each point that are covered by maximum number of balloons possible
    // to find these points, we need to keep track of the area covered by all balloons that we met until now (while moving from left to right on X-axis)

    // if we look at the first example,
    // we can see that the balloons cover intersecting areas like this:
    // .......
    //   .........
    //          ........
    //               ........
    // so we need to throw arrows at any point in these areas
    // ..|.....|
    //   |.....|....
    //          .....|...|
    //               |...|.....
    // these areas can form a new set of intervals which we need to keep track of, and throw an extra arrow once we find a new interval that doesn't intersect with the current one we have
    
    // to do this, we need to maximize the starting point of these intervals, and minimizing the ending point
    // if the beginning of an interval does not belong to the current (max, min), we have to start a new interval and increase the number of arrows by one


    // obviously, we need to sort the original intervals by the starting point in order to make sure that if the next interval does not belong to the current, then also no other interval does
    points.sort((a, b) => a[0] - b[0]);


    // we want always to take the first interval as a starting interval, so we need to set the initial start and end as minimum possible and maximum possible
    let left = -Infinity, right = Infinity;
    let cnt = 0; // count of arrows needed

    // iterate over each point in the sorted array
    points.forEach(point => {
        // if the start of this interval exceeds the end of our current interval
        if(point[0] > right){
            // we need an arrow for the interval we have
            cnt++;
            // re-initialize the current interval by the latest met one
            left = point[0], right = point[1];
        }else{
            // if we can join this interval to the current one, we maximize the start and minmize the end
            left = Math.max(left, point[0]);
            right = Math.min(right, point[1]);
        }
    });

    // increase the count by one because that the last interval is not counted yet
    return ++cnt;
};

// notice that we only used the end point of our intervals to determine if we need another arrow or not
// so we can optimize more and dicard keeping track of start points of our intervals (minimize the end only)