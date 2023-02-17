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
  const a = "a".charCodeAt(0); // get the ASCII code of ("a" - "b" is NaN) so we have to do it that way
  if (words.length === 1) return true; // if there is only a word then it is sorted.
  const orderMap = new Array(26); // an array to store the order of each letter

  let i = 0; // the order of each letter is the position it appers at
  for (const ch of order) orderMap[ch.charCodeAt(0) - a] = i++;

  function isSorted(w1, w2) {
    let i = 0,
      j = 0;

    while (i < w1.length && j < w2.length) {
      const ch1 = w1[i].charCodeAt(0);
      const ch2 = w2[j].charCodeAt(0);
      if (orderMap[ch1 - a] > orderMap[ch2 - a]) return false;
      else if (orderMap[ch1 - a] < orderMap[ch2 - a]) return true;
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
