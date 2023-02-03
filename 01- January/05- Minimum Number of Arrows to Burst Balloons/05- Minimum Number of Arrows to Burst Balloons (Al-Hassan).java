// Author : Al-Hassan Ali

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));    
        int ans = 1;
        int end = points[0][1];
        for(int i = 1; i < points.length; i++) {
            if(points[i][0] > end) {
                ans++;
                end = points[i][1];
            }
        }
        return ans;
    
    }
}
