// Author: Mohamed Tolba

class Solution {
  bool detectCapitalUse(String word) {
    // input string shorter than 2 characters
    if (word.length < 2) return true;

    // all characters are uppercase
    if (word.toUpperCase().contains(word)) return true;

    // all characters are lowercase
    if (word.toLowerCase().contains(word)) return true;

    // all characters after the first are lowercase
    if (word.substring(1).toLowerCase().contains(word.substring(1))) return true;

    return false;
  }
}
