// Author: Hamza Hassanain (hamzahasa067)
/*
    Intuition: Since our constrainers are too small (max N is 100) 
                we can easily find a brute-force solution
    Approach
        Find the co-ordinates of water (0s)
        Find the co-ordinates of land (1s)
        If one of our arrays is empty then we return -1 as stated in the problem statement
        Then we iterate over our water array and find the minimum distance between this piece of water and the land (this way we get the distance from the nearest land)
        Then we find the maximum between the minimums
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function (grid) {
  const n = grid.length;
  const land = [];
  const water = [];
  // Find the co-ordinates of water (0s), Find the co-ordinates of land (1s)
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!grid[i][j]) water.push([i, j]);
      else land.push([i, j]);
    }
  }
  // If one of our arrays is empty then we return -1 as stated in the problem statement
  if (!land.length || !water.length) return -1;

  let res = -1e9;

  // iterate over our water array and find the minimum distance between this piece of water and the land
  // (this way we get the distance from the nearest land)
  // Then we find the maximum between the minimums
  for (let i = 0; i < water.length; i++) {
    let minDist = 1e9;
    for (let j = 0; j < land.length; j++)
      minDist = Math.min(
        minDist,
        Math.abs(water[i][0] - land[j][0]) + Math.abs(water[i][1] - land[j][1])
      );

    res = Math.max(minDist, res);
  }
  return res;
};
