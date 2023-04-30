// Author: Ahmed Gamal

// the idea for this solution is so simple, let's look at the following observations:
// 1- each bulb will be on after the number of its factors is odd
// 2- each number has even number of factors except the perfect squares (because each factor has a pair in the other side of the number, except the perfect squares)
// 3- so the number of bulbs that will be on is the number of perfect squares less than n

// since the perfect squares are growing so fast, we will loop until the square of the number is less than or equal n (at most sqrt(n))

// or we can use the following formula to calculate the number of perfect squares less than n:
// Math.floor(Math.sqrt(n)), why?
// because the perfect squares are the squares of the numbers from 1 to Math.floor(Math.sqrt(n)), so every integer from 1 to Math.floor(Math.sqrt(n)) will have a perfect square less than or equal n, so the number of perfect squares less than n is Math.floor(Math.sqrt(n))

/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function(n) {
    return Math.floor(Math.sqrt(n));
};