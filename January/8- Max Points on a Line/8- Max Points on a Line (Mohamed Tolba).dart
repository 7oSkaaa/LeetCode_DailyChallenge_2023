// Author: Mohamed Tolba

import 'dart:math';

class Solution {
  int maxPoints(List<List<int>> points) {
    int n = points.length, ans = 1;
    for (int i = 0; i < n - 1; i++) {
      // store <slope,that selected point>
      Map<double, int> mp = {};
      for (int j = i + 1; j < n; j++) {
        if (points[j][1] == points[i][1]) {
          mp[-90] = (mp[-90] ?? 0) + 1;
        } else {
          var dy = (points[j][0] - points[i][0]);
          var dx = (points[j][1] - points[i][1]);
          double slope = dy / dx;
          // count the number of points that have the same slope
          mp[slope] = (mp[slope] ?? 0) + 1;
        }
      }
      int temp = 0;
      for (MapEntry<double, int> it in mp.entries) {
        temp = max(temp, it.value + 1);
      }
      ans = max(temp, ans);
    }
    return ans;
  }
}
