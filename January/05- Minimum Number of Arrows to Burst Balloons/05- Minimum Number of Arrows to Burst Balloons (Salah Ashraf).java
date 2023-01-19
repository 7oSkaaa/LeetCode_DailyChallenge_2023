// Author: Salah Ashraf


class Solution {
    public int findMinArrowShots(int[][] points) {
        //sort the 2 D Array ascendingly
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int numberOfArrows = 1, pointShooted = points[0][1];
        for (int i = 1; i < points.length; i++) {
            //if arrow less than point[x start]
            //then we increment number of arrows
            if (points[i][0] > pointShooted) {
                numberOfArrows++;
                pointShooted = points[i][1];
            }
        }
        return numberOfArrows;
    }
}
