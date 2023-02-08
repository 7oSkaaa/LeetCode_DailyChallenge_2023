// Author: Hamza Hassanain (hamzahasa067)
/*
Approach: Initialize a window on s2 of size s1 and check if it contains one permutation of 
            s1 then  we return true otherwise we update our window and move it by one
            
            a window is a substring of s2 with left pointer and right pointer
            valid window means it contains all letters from s1 with their frequencies
        */
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */

var checkInclusion = function (s1, s2) {
  if (s1.length > s2.length) return false;
  const a = "a".charCodeAt(0);

  const mp1 = new Array(26).fill(0); // map all our letters of string s1 to validtate the window
  const windowMP = new Array(26).fill(0); // map letters of the window
  for (const ch of s1) mp1[ch.charCodeAt(0) - a]++; // Initialize the mp1 of all letters and their frequencies on s1

  let l = 0; // begining of the window
  let r = s1.length - 1; // end of the window
  for (let i = 0; i <= r; i++) {
    // the initial window
    windowMP[s2[i].charCodeAt(0) - a]++;
  }
  while (l <= r && r < s2.length - 1) {
    if (mp1.every((val, i) => val === windowMP[i]))
      // check if the two arrays have the same value for each position
      return true; // if the window is valid return
    else {
      // update the window
      windowMP[s2[l].charCodeAt(0) - a]--; // remove the left character
      l++;
      r++;
      // move one to right;
      windowMP[s2[r].charCodeAt(0) - a]++; // add the newly added character
    }
  }

  return mp1.every((val, i) => val === windowMP[i]);
};
