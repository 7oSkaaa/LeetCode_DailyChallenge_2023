// Author: Hamza Hassanain (hamzahasa067)
/*
    Approach: Initialize a window on s of size p and check if it contains all letters of 
            p then  we add left pointer to the result array otherwise we update our window and move it by one from left and right
            a window is a substring of s with left pointer and right pointer
            valid window means it contains all letters from p with their frequencies
*/
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
  if (p.length > s.length) return []; // if p is grater than s then return empty array
  const res = [];
  const a = "a".charCodeAt(0);
  const pMap = new Array(26).fill(0);
  const windowMap = new Array(26).fill(0);

  // Initialize the pMap of all letters and their frequencies on p
  for (const ch of p) pMap[ch.charCodeAt(0) - a]++;

  let l = 0;
  let r = p.length - 1;

  // Initialize the windowMap of all letters and their frequencies on s
  for (let i = l; i <= r; i++) windowMap[s[i].charCodeAt(0) - a]++;

  while (r < s.length - 1) {
    // if the two arrays are equal we add the left pointer to the array
    if (pMap.every((freq, i) => freq === windowMap[i])) res.push(l);

    // update our window
    const lCode = s[l].charCodeAt(0) - a;
    const rCode = s[r + 1].charCodeAt(0) - a;
    windowMap[lCode]--;
    windowMap[rCode]++;

    l++;
    r++;
  }
  pMap.every((freq, i) => freq === windowMap[i]) && res.push(l);

  return res;
};
