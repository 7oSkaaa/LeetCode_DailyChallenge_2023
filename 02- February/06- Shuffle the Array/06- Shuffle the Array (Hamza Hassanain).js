// Author: Hamza Hassanian (hamzahasa067)
/*
    Approach: since the larget number will be present in our array is 1000 we can use this to our 
            advantage. Instead of creating an extra array to store our result we will be using only
            the input array.
            We are given and array [x1,x2,x3,y1,y1,y1] we want [x1,y1,x2,y2,x3,y3] as output
            for every i < n we will encode xi,yi in the ith position as follows 
            nums[i] = xi + (yi * 10000)
            then we will then decode nums[i] and get our result

*/
/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function (nums, n) {
  const key = 10000; // our key to encode

  for (let i = 0; i < n; i++) nums[i] += nums[i + n] * key;

  let cur = 2 * n - 1;

  for (let i = n - 1; i >= 0; i--) {
    const temp = nums[i]; // store it in a temp to avoid confilct with nums[cur - 1]

    nums[cur - 1] = temp % key; // to get xi
    nums[cur] = (temp - nums[cur - 1]) / key; // to get yi

    cur -= 2;
  }
  return nums;
};
