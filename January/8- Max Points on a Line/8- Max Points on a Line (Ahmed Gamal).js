// Author: Ahmed Gamal
/**
 * @param {number[][]} points
 * @return {number}
 */
let maxPoints = function(points) {
    // to count the number of points on lines, we need to categorize the points by something unique
    // that's right! we will categorize the points by the lines that pass through them
    // one way to define a line is by a point and the slope
    // so, we will use brute force and try to treat each point as our unique point, and find all slopes of the lines created by it and each of the other points
    // that's impossible to have two different lines that have the same slope and pass by the same point in the same time

    // to find the slope of two given points
    let getSlope = (a, b) => {
        // if the line is parallel to x-axis
        if(a[0] === b[0])
            return Infinity; // unique value that cannot be produced in any other case
        // (y2 - y1) / (x2 - x1)
        return (b[1] - a[1]) / (b[0] - a[0]);
    };

    // if we have just one point, we will not check any pairs and will return the answer immediately
    // that is why we are initializing it with 1 instead of any other smaller value
    let ans = 1;
    // the outer loop represents the current point we are considering to find all the lines pass through it
    for(let i = 0; i < points.length; i++){
        // a hash map to store how many points lie on the same line (defined by the point points[i] and the slope)
        const map = new Map();

        // the inner loop represents all of the other points we are considering as a second point on some line that passes through points[i]
        for(let j = i + 1; j < points.length; j++){
            // get the slope of the line that passes through these two points
            let slope = getSlope(points[i], points[j]);
            // if this slope is not found in the map, create it and initialize it with the value 1 (because we have already points[i] lies on it)
            if(!map.has(slope))
                map.set(slope, 1);
            // we found that points[j] lies on some line, so we will increase the count of the points lie on it by 1
            map.set(slope, map.get(slope) + 1);
            // we want to maximize the answer by taking the maximum of the maximum number of points that lie on each of the lines we will define
            ans = Math.max(ans, map.get(slope));
        }
    }

    return ans;
};