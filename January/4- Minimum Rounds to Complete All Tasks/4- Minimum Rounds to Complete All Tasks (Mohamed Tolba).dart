// Author: Mohamed Tolba

class Solution {
  int minimumRounds(List<int> tasks) {
    // Create a Map to store the count of each task
    Map<int, int> mp = {};

    int result = 0;

    // Iterate through the tasks array and store the count of each task in the Map
    for (int i in tasks) {
      mp[i] = (mp[i] ?? 0) + 1;
    }

    // Iterate through the values in the Map (which represent the counts of the tasks)
    for (int v in mp.values) {
      // If a task has a count of 1, it cannot be grouped with other tasks and so we return -1
      if (v == 1) return -1;

      // Add the number of rounds needed to process the tasks with count greater than or equal to 3
      if (v % 3 == 0) {
        result += v ~/ 3;
      } else {
        result += v ~/ 3 + 1;
      }
    }

    return result;
  }
}
