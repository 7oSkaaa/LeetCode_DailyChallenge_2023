# Author: Lobna Mazhar

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # Sort Points to consider intersection between end of current and start of next
        points.sort()

        # Compare last point with the current point, so start by adding first point to the final result
        res = []
        res.append(points[0])
        for i in range(1, len(points)):
            # If the current point intersects with the last point
            if points[i][0] <= res[-1][1]:
                # Merge the 2 points where the start is the current start and the end is the minimum between the 2 ends
                last = res.pop()
                res.append([points[i][0], min(points[i][1], last[1])])
            # Else if there is no intersection, add the current point to the end of the result
            else: res.append(points[i])
        # The length of the result shows how many points with no intersections, hence they need separate arrows
        return len(res)