// Author: Ahmed Gamal

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

// we need to find the number of subarrays whose sum is divisible by k
// we can use the prefix sum technique to solve this problem by getting benefit from the fact that if we have a number x whose remainder is r when divided by k
// to subtract a number from x to make it divisible by k, we need to subtract a number whose remainder is r when divided by k
// for example, if x = 10 and k = 3, x % k = 1
// to make x divisible by k, we need to subtract a number whose remainder is 1 when divided by k like 1, 4, 7, and so on (also negative numbers give correct remainder when divided by k if we add a multiple of k to them)
// we can use the sum of the subarray from the beginning of the array to the current index to get the number x
// we want to find the number of subarrays (prefixes) which we can subtract their sum from x to make it divisible by k
// this will definitely be the number of prefixes whose sum is divisible by k
// so, we can use a map to store the number of prefixes whose remainder is r when divided by k

var subarraysDivByK = (nums, k) => {
    // map: a map to store the number of prefixes whose remainder is rem when divided by k
    const map = new Map();

    // ans: the number of subarrays whose sum is divisible by k (initially 0)
    // sum: the sum of the subarray from the beginning of the array to the current index (initially 0)
    let sum = 0, ans = 0;
    nums.forEach(x => {
        // update the sum by adding the current number
        sum += x;
        
        // get the remainder of the sum when divided by k (we need to add k to the remainder to make it positive if it's negative because the remainder of a negative number when divided by k is negative)
        let rem = (sum % k + k) % k;
        
        // if the map doesn't have the remainder, add it with value 0
        if(!map.has(rem))
            map.set(rem, 0);

        // update the answer by the number of prefixes whose remainder is rem when divided by k
        // if the remainder is 0, we can add 1 because the current prefix is divisible by k
        ans += map.get(rem) + (rem === 0);

        // update the number of prefixes whose remainder is rem when divided by k by adding 1
        map.set(rem, map.get(rem) + 1);
    });

    // return the number of subarrays whose sum is divisible by k
    return ans;
};