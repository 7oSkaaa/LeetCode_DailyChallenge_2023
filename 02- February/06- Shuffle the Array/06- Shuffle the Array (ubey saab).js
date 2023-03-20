//Author: Ubey Saab
var shuffle = function (nums, n) {
  let answer = []; //create a new array
  let i = 0; //counter
  if (nums.length == 2) {
    // if length is equal to 2 return nums
    return nums;
  }

  while (i < n) {
    //while i smaller than n which is distant between x and y elements
    answer.push(nums[i]); // add the element to  end of answer
    answer.push(nums[i + n]);
    i++;
  }
  return answer;
};
