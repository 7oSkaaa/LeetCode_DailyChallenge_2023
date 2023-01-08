# Author: Lobna Mazhar

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # If one point was given, return 1
        if len(points) == 1: return 1

        # Make a table to count how many points on the same line from a point
        table = defaultdict(int)
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                # If the 2 points occur on the same x-axis, mark the slope as -1
                if (points[i][0] == points[j][0]): res = sys.maxsize
                # If the 2 points occur on the same y-axis, mark the slope as -2
                elif (points[i][1] == points[j][1]): res = 0
                # else, calculate the slope between the 2 points
                else: res = self.calculateSlope(points[i], points[j])
                table[(i, res)] += 1
        # Return the highest slope count for a point and add 1 for the point
        return max(table.values()) + 1

    # Helper method to calculate slope
    def calculateSlope(self, point1, point2):
        return (point2[1] - point1[1]) / (point2[0] - point1[0])