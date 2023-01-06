// Author: Mohamed Tolba

class Solution {
  int findMinArrowShots(List<List<int>> points) {
    // sort the points by the end
    points.sort((a, b) => a[1].compareTo(b[1]));
    int ans = 0, end = points[0][1];

    // Traverse the array and compare the end time with each balloon's start time
    // because if any balloon's start time is less than or equal time to previous
    // end time that means those balloons can be shot with same arrow.
    for (int i = 0; i < points.length; i++) {
      // If any balloon's start time is bigger than previous end time that means they
      // do not share common area and new balloon will need a new arrow to shot
      if (ans == 0 || points[i][0] > end) {
        ans++;
        end = points[i][1];
      }
    }

    return ans;
  }
}
