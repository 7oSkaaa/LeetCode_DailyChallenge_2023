//Author: Mohamed Ibrahim

class Solution {
public:
int maxPoints(vector<vector<int>>& points) {
    // Map to store the number of lines with a given slope
    unordered_map<double, int> slopeCount;
    int maxCount = 0;
    // If there is only 1 point, return 1
    if(points.size()==1) return 1;
    // Iterate through the points
    for (int i = 0; i < points.size(); i++) {
        // Reset the map and count for each point
        slopeCount.clear();
        int count = 1; // At least one point on the line
        // Calculate the slope of the line formed by this point and every other point
        for (int j = 0; j < points.size(); j++) {
            // Skip the current point
            if (i == j) continue;
            double slope = (points[j][1] - points[i][1]) * 1.0 / (points[j][0] - points[i][0]);
            // Increment the count for this slope in the map
            slopeCount[slope]++;
            // Update the count for the maximum number of points on this line
            count = max(count, slopeCount[slope]);
        }
        // Update the maximum count, adding 1 for the current point
        maxCount = max(maxCount, count + 1);
    }
    return maxCount;
}
};