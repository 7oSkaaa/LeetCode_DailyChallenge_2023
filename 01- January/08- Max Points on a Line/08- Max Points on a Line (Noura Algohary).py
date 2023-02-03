# Author: Noura Algohary
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        max_points = 0
        slope = 0.0

        for i in range(len(points)):
            # A dictionary that stores slopes as keys and the frequency of occurrence as value
            slopes = {}

            # clearing is important for the next loop 
            vertical = 0
            slope = 0.0

            for j in range(len(points)):
                if i==j:    #The same point, then skip it.
                    continue

                # When the denominator is equal to 0, the points are vertical and slope is not defined. 
                # "vertical" counts vertical points.
                if points[i][0] == points[j][0]: 
                    vertical += 1
                    continue

                # point1(x1, y1), point2(x2, y2) --> slope = (y2 - y1) / (x2 - x1)
                slope = float(points[i][1] - points[j][1]) / float(points[i][0] - points[j][0])

                if slope in slopes:  # slope is already a key on the dict
                    slopes[slope] += 1
                else:
                    slopes[slope] = 1   # add slope to the map with a 0 frequency.

            if len(slopes) !=0:
                freq = max(slopes.values())

                if freq > max_points:
                    max_points = freq

            # if vertical > 0, then there are some vertical points counted
            if vertical > max_points:
                max_points = vertical

        return 1 + max_points