// Author: Ahmed Gamal

/**
 * @param {number[]} salary
 * @return {number}
 */

var average = function(salary) {
    let ans = 0;

    // sort the array to get the minimum and maximum values in the first and last index, then loop through the array and add all values except the first and last values
    salary.sort((a, b) => a - b).forEach((val, idx) => {
        if(idx !== 0 && idx !== salary.length - 1) {
            ans += val;
        }
    });

    // divide the sum by the length of the array - 2 to get the average
    ans /= salary.length - 2;

    // return the average
    return ans;
};