// Author: Ahmed Gamal

// the idea for this solution is so simple, we will loop until the number is less than 10
// in each iteration we will calculate the sum of the digits of the number

/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    // loop until the number is less than 10
    while(num > 10) {
        // calculate the sum of the digits of the number
        // x: copy of the number to not change the original number
        // sum: the sum of the digits of the number

        // loop until the number is 0
        // in each iteration we will add the last digit to the sum
        // and remove the last digit from the number

        let x = num, sum = 0;
        while(x) {
            sum += x % 10;
            x = Math.floor(x / 10);
        }

        // update the number with the sum
        num = sum;
    }

    // return the number
    return num;
};