// Author: Ahmed Gamal

// for this problem, we just need to keep track of two important things that determine the sign of the product of the array:
// 1- if the array contains a zero, then the product will be zero (regardless of the other values in the array)
// 2- if the array contains an odd number of negative values, then the product will be negative, otherwise it will be positive

/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function(nums) {
    // odd: true if the number of negative values is odd, false otherwise
    // zero: true if the array contains a zero, false otherwise
    let odd = false, zero = false;

    // loop through the array and update the values of odd and zero
    nums.forEach(x => {
        // if x < 0, then odd will be true if it was false, and false if it was true (using XOR)
        odd ^= x < 0;

        // if x === 0, then zero will be true
        zero |= x === 0;
    });
    
    // if zero is true, then the product will be zero regardless of the value of odd
    if(zero) {
        return 0;
    }

    // if odd is true, then the product will be negative, otherwise it will be positive
    return (odd && -1) || 1;
};