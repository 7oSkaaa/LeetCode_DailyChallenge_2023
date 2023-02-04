# Author: Mohamed Aly Elsayed Matar

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # initaialize the result of arrows with 1 since we will always throw one
        # and we don't know when we will finish
        res = 1
        # sort the list according to the ending point (the second element in the list)
        points.sort(key = lambda x: x[1])
        # initialize the minimum end point to compare with
        min = points[0][1]
        # iterate in the range of the ballons
        for i in range(len(points)):
            # compare the each start point with the minimum
            # if less than or equal to the minimum, continue
            if points[i][0] <= min:
                continue
            # else, set the end point of that start point to be the minimum
            # and increment the result of arrows
            else:
                min = points[i][1]
                res += 1
        return res