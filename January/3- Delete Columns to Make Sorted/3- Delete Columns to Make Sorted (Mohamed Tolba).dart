// Author: Mohamed Tolba

class Solution {
  int minDeletionSize(List<String> strs) {
    // Variable to store the count of columns to be deleted.
    int ans = 0;

    // Iterate over each index in the string.
    for (int i = 0; i < strs.first.length; i++) {
      // Iterate over the strings.
      for (int j = 1; j < strs.length; j++) {
        // Characters should be in increasing order,
        // If not, increment the counter.
        if (strs[j].codeUnitAt(i) < strs[j - 1].codeUnitAt(i)) {
          ans++;
          break;
        }
      }
    }

    return ans;
  }
}
