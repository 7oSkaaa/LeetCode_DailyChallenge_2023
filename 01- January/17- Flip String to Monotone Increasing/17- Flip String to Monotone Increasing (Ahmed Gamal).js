// Author: Ahmed Gamal

/**
 * @param {string} s
 * @return {number}
 */

// to solve this problem we need to find the minimum number of flips to make the string monotone increasing
// simply, we can try all possible points to flip the left part's 1s to 0s and the right part's 0s to 1s
// and find the minimum number of flips

// so, we can start from the first index and try to flip the left part's 1s to 0s and the right part's 0s to 1s
// this can be done by counting the number of 1s in the left part (prefix) and the number of 0s in the right part (length - suffix ones)
// the number of flips to make in the left part is prefix and the number of flips to make in the right part is remaining length (length - index) - suffix ones


var minFlipsMonoIncr = s => {

    // prefix = number of 1s in the left part (before the current index) (initially 0)
    // suffix = number of 1s in the right part (starting from the current index) (initially the number of 1s in the string)
    
    // we can count the number of 1s in the string by using regex match or split
    // regex match will return an array of all the matches, so we can get the length of the array to get the number of 1s
    // split will return an array of the string split by the given character, so we can get the length of the array - 1 to get the number of 1s
    let prefix = 0, suffix = s.match(/1/g).length;
    // suffix = s.split('1').length - 1

    // ans = the minimum number of flips to make the string monotone increasing (initially Infinity)
    let ans = Infinity;
    // loop over the string (convert it to an array of characters to be able to use forEach method on it)
    [...s].forEach((x, idx) => {
        // update the answer by the minimum between the current answer and the number of flips to make in the left part + the number of flips to make in the right part
        ans = Math.min(ans, prefix + s.length - idx - suffix);

        // update the number of 1s in the left part by adding 1 if the current character is 1
        // update the number of 1s in the right part by subtracting 1 if the current character is 1
        prefix += x === '1';
        suffix -= x === '1';
    });

    // return the minimum number between the current answer and the choise of flipping all the 1s in the string to 0s
    return Math.min(ans, prefix);
};