// Author: Hamza Hassanain (hamzahasa067)
/*
    Approch:
        1- Map letters on the order string to a map where the key is the letter and the value is the order (the index it appers at)
        2- Check every two adjacent words in the word string if two adjacent words are not sorted properly then we return false
        3- If each two adjacent words are sorted then the words array is sorted by definition 
*/
/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */

function isAlienSorted(words, order) {
  if (words.length === 1) return true; // if there is only a word then it is sorted.
  const orderMap = new Map(); // a hash Map to store the order of each letter

  let i = 0; // the order of each letter is the position it appers at
  for (const ch of order) orderMap.set(ch, i++);

  function isSorted(w1, w2) {
    let i = 0,
      j = 0;

    while (i < w1.length && j < w2.length) {
      if (orderMap.get(w1[i]) > orderMap.get(w2[j])) return false;
      else if (orderMap.get(w1[i]) < orderMap.get(w2[j])) return true;
      else i++, j++;
    }
    /*
        if we get to the end of one of two words this that one word is shorter than the other then we have to make sure that 
        the smaller one comes first as stated in the problem statment:
        "According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character"
    */
    return w1.length <= w2.length;
  }

  for (let i = 0; i < words.length - 1; i++) {
    const w1 = words[i];
    const w2 = words[i + 1];
    if (!isSorted(w1, w2)) return false;
  }

  return true;
}
