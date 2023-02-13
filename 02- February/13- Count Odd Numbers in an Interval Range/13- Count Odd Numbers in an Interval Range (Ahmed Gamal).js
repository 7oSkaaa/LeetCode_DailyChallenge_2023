// Author: Ahmed Gamal

/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */

// for this problem we need to find the number of odd numbers between low and high
// we can do this by finding the length of the range and dividing it by 2 (integer division) and adding 1 if the low is odd and the range is odd
// why? because if the low is odd then the first number in the range is odd and we need to add it to the count
// otherwise if the low is even then the first number in the range is even and we don't need to add it to the count
// in the other cases the division by 2 will give us the correct count because if the range is even then out of every 2 numbers in the range one is odd


var countOdds = function(low, high) {
    // length of the range
    let length = high - low + 1;

    // if the range is even then we don't need to add 1 to the count
    // otherwise if the range is odd then we need to add 1 to the count if the low is odd
    return Math.floor(length / 2) + (low % 2 * (length % 2 ? 1 : 0));
};