// Author: Hamza Hassanain (hamzahasa067)

/*
    Approch: [2,3,1,1,4] => split the array into levels 
            => [ [2], [3,1] , [1,4]  ] => the number of levels is our solution, we will use a kind 
            of a sliding window approach
*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function (nums) {
  const n = nums.length;
  let l = 0,
    r = 0,
    res = 0;

  while (r < n - 1) {
    let levelSize = 0; // the size of the next Level
    for (let i = l; i < r + 1; i++)
      levelSize = Math.max(levelSize, i + nums[i]); // the distance between our position and the
    // nums[i] which is the maximum jump we can get

    l = r + 1;
    r = levelSize;
    res++;
  }
  return res;
};
