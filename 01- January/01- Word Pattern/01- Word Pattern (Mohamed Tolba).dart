// Author: Mohamed Tolba

class Solution {
  bool wordPattern(String pattern, String s) {
    // s is the sentence so we breaking it into each and every single word
    List<String> words = s.split(' ');

    Map index = {};
    // Check if words and pattern are of different length there can be no mapping
    if (words.length != pattern.length) return false;

    for (int i = 0; i < words.length; i++) {
      // If the key already exists, the current value is returned.
      final result = index.putIfAbsent(pattern.indexOf(pattern[i]), () => i);
      if (result != index.putIfAbsent(words[i], () => i)) return false;
    }
    return true;
  }
}