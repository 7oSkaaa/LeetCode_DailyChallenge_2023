// Author: Ahmed Gamal

/**
 * @param {string} s
 * @return {string[][]}
 */


// we want to split the string into palindromes (we want to find all possible partitions)
    // we can use backtracking to try all possible combinations since the number of combinations is small
    // we will use a vector<string> curr to store the current combination
    // we will use a vector<vector<string>> ans to store all valid combinations
    // we will use a string tmp to store the current string we are trying to add to curr
    // we will use a bool is_palindrome(string& str) function to check if a string is a palindrome
    // we will use a void rec(int st, string& s) function to try all possible combinations


// check if a string is a palindrome
let isPalindrome = s => {
    for(let l = 0, r = s.length - 1; l <= r; l++, r--)
        if(s[l] != s[r])
            return false;
    return true;
}

let ans = [], curr = [];

// try all possible combinations
let rec = (st, s) => {
    // if we reached the end of the string, we found a valid combination
    if(st >= s.length){
        // add the current combination to ans (we need to copy it because curr will be modified)
        ans.push([...curr]);
        return;
    }

    let tmp = [];
    for(let i = st; i < s.length; i++){
        // try to add the current string to curr
        tmp.push(s[i]);
        // if the current string is a palindrome, we can add it to curr (we will try to add the rest of the string in the next iteration)
        // we are using a list to store the current string because it is faster to add and remove elements from the end of a list than from a string (string concatenation is slow in javascript because it creates a new string every time (immutable strings)))
        // we join the list to convert it to a string (and we can just keep it as a list, this would be even faster, but this is for educational purposes)
        if(isPalindrome(tmp.join(''))){
            // add the current string to curr
            curr.push(tmp.join(''));
            // try to add the rest of the string
            rec(i + 1, s);
            // remove the current string from curr (we will try to add a different string in the next iteration)
            curr.pop();
        }
    }
}

let partition = s => {
    ans = [], curr = [];
    rec(0, s);
    return ans;
};