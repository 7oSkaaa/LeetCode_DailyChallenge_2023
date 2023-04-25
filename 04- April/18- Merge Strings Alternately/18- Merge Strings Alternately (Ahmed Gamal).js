// Author: Ahmed Gamal

// for this problem we can use two pointers to iterate over the two strings and add the character to the answer string
// we can use a boolean variable to determine which string to add the character from
// we can use a XOR operation to toggle the boolean variable
// we need to check if the string is finished before adding the character to the answer string

/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    // i: index of word1
    // j: index of word2
    // turn: boolean variable to determine which string to add the character from
    // ans: answer string
    let i = 0, j = 0, turn = true;
    let ans = [];

    // iterate while one of the strings is not finished
    while(i < word1.length || j < word2.length) {
        // check if the string is finished before adding the character to the answer string
        if(turn && i < word1.length) {
            ans.push(word1[i++]);
        } else if(j < word2.length) {
            ans.push(word2[j++]);
        }
        // toggle the boolean variable
        turn ^= 1;
    }

    // return the answer string
    return ans.join('');
};