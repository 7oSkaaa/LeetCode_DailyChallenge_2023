// Author: Ahmed Gamal

/**
 * @param {number[]} nums
 * @return {number[][]}
 */

// we need to find the number of non-decreasing (sorted) subsequences of length at least 2
// since the size of the original array is at most 15, we can use bitmasking to generate all possible subsequences (the power set of the array size is 2^15 = 32768)
// the idea is to generate the subsets according to the bits of the current number (from 0 to 2^15 - 1)
// for example, if we have the array [1, 2, 3, 4] and the current number is 5 (101 in binary), the current subset is [1, 3]
// we can check if the current subset is non-decreasing by checking if it's sorted
// if it's sorted, we can add it to the answer
// we can use a set to store the subsequences as strings to avoid duplicates (this is special in javascript because it doesn't compare arrays by their values but by their references)
// so we can have to arrays with the same values but different references and the set will consider them as different values
// to avoid this, we can convert the arrays to strings and store them in the set and then convert them back to arrays (because the set doesn't store the references of the values but the values themselves)
// we can use the join method to convert the array to a string and the split method to convert the string to an array

let findSubsequences = nums => {
    // ans: the non-decreasing subsequences of length at least 2
    let ans = [];

    // isSorted: a function to check if the given list is sorted
    const isSorted = (list) => {
        for(let i = 1; i < list.length; i++){
            if(list[i] < list[i - 1])
                return false;
        }
        return true;
    };

    // n: the size of the original array
    const n = nums.length;
    // the outer loop iterates over all possible numbers from 0 to 2^n - 1
    for(let i = 0; i < (1 << n); i++){
        // seq: the current subset
        let seq = [];
        // the inner loop iterates over all bits of the current number
        for(let j = 0; j < n; j++){
            // if the current bit is 1, add the corresponding element to the current subset
            if(i & (1 << j)){
                seq.push(nums[j]);
            }
        }
        // if the current subset is non-decreasing and has length at least 2, add it to the answer
        if(seq.length >= 2 && isSorted(seq))
            // convert the array to a string and add it to the set
            ans.push(seq.join(' '))
    }

    // use Set to remove duplicates and then convert the strings back to arrays
    return [...new Set(ans)].map(x => x.split(' '));
};