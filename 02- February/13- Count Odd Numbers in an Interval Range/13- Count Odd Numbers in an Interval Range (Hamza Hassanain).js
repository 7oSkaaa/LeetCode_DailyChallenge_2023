// Author: Hamza Hassanain

/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function (low, high) {
  if (low === high) return low % 2;

  !(low % 2) && low++;
  !(high % 2) && high--;

  return (high - low + 2) / 2;
};
