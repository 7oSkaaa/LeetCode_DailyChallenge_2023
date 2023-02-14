// Author: Ahmed Gamal

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

// for this problem we need to add two binary numbers
// we can do this manually by adding the numbers bit by bit from the right to the left and keeping track of the carry
// we can also do this by converting the numbers to decimal and adding them and then converting the result to binary (we need to use BigInt for this if the numbers are large like in the problem)

// when we add two binary numbers, the current bit is the sum of the two bits and the carry from the previous bit (if there is one) modulo 2 (because the sum of two bits can be 0, 1, 2 or 3)
// the carry is the sum of the two bits and the carry from the previous bit divided by 2
// the two strings can have different lengths so we need to pad the shorter string with zeros to make them the same length for easier implementation (for example 101 + 1111 = 0101 + 1111)

var addBinary = function(a, b) {
    // if the first string is longer than the second string then we need to swap them to make the first string the shorter one
    // this is because we need to pad the shorter string with zeros to make them the same length and we don't want to consider many cases
    if(a.length > b.length){
        [a, b] = [b, a];
    }
    
    // pad the shorter string with zeros to make them the same length
    // we create an array of zeros with the length of the difference between the two strings and then we join them to make a string of zeros
    // then we add the zeros to the beginning of the shorter string
    a = Array(b.length - a.length).fill(0).join('') + a;

    // carry is the sum of the two bits and the carry from the previous bit divided by 2
    // ans is the result of the addition
    let carry = 0, ans = "";

    // we loop from the end of the strings to the beginning
    // we use the bitwise NOT operator to convert the value of i to a boolean and then we negate it to get the boolean value of the condition
    // it is the same as writing i >= 0 (the condition is true if i is greater than or equal to 0, and it will be false once i becomes -1)
    for(let i = a.length - 1; ~i; i--){

        // first we add the two bits and the carry from the previous bit and subtract 48 * 2 because the characters are represented by their ASCII codes
        // then we divide the sum by 2 to get the carry
        // then we take the modulo 2 to get the current bit
        // then we add the current bit to the result
        // we use Math.floor to get the integer part of the division

        let currBit = a.charCodeAt(i) + b.charCodeAt(i) - 48 * 2 + carry;
        carry = Math.floor(currBit / 2);
        currBit %= 2;
        ans += currBit;
    }

    // we add the carry if there is one, otherwise we don't add anything (the empty string)
    // we reverse the result because we added the bits from the right to the left
    // to do this we convert the string to an array of characters, reverse the array and then join the characters to make a string
    return [...(ans + (carry ? carry : ''))].reverse().join('');
};

// for the solution that uses BigInt we can use the toString method to convert the result to binary
// the solution will be just one line of code
// return (BigInt('0b' + a) + BigInt('0b' + b)).toString(2);
// or we can use string literals
// return (BigInt(`0b${a}`) + BigInt(`0b${b}`)).toString(2);
