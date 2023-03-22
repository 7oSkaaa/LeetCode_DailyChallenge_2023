//Author : ubey saab
var findKthPositive = function (arr, k) {
  let index = 0;
  let counter = 1;
  let answer = [];
  while (answer.length <= 1000) {
    if (counter < arr[index]) {
      //if counter is smaller than the current element add counter to the new array because counter is missing
      answer.push(counter);
    } else if (counter >= arr[index]) {
      //if equal or bigger that mean you need to look at the next index
      index++;
    } else {
      //when arr is finished but we still need to fill answer array until the length of it equal 1000
      answer.push(counter);
    }
    counter++;
  }
  return answer[k - 1]; //k-1 because in arrays we start counting from zero
};
