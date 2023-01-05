Author: Anas Maher

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int i=1, res=1, n=points.size(); // res = 1 because thats the minimum possible answer.
        sort(points.begin(), points.end());
        // (1,6) (2,8) (7,12) (10,16)

        while(i<n)
        {

            // (points[i][0], points[i][1]) -> (x-start,x-end) for the i-th balloon.
            // check if the current balloon is in the range of the previous one:

            /* x1-start ------------ x1-end
                  x2-start-------------------------x2-end*/
            
            /* from the above, for balloon 2(x2) to be in the interval of balloon 1(x1),
               x2-start must be between x1-start and x1-end,
               for x2-end it doesnt matter if its in or out the range. 
            */


            if(points[i][0]>=points[i-1][0] && points[i][0]<=points[i-1][1])
            {
                points[i][1] = min(points[i][1], points[i-1][1]);
            /*
               (1,6) (2,8) (7,12) (10,16)
               in this case, "7" would be in the range of the previous balloon, but out 
               of the first one range, we need to make sure that there is intersection 
               between all balloons until now, not only the previous one. 
            */

            /*
               (1,6) (2,8) (7,12) (10,16)
               by taking the minimum end of each intersection, we are limitng the "big" 
               interval to the minimum end to make sure that we are checking the next
               balloon with every other balloon in the big interval, not only the previous one. 
            */

            /*
               (1,6) res --> 1
               (2,8) intersection, (2,8) --> (2,6), res still 1, same arrow
               (2,6) (7,12) out of range 7 > 6, need one more arrow, res --> 2, begin of a new big interval.
               (10,16) intersection, (10,16) --> (10,12), res still 2, same arrow
               answer = 2 arrows.
            */

            }
            else 
            {
                res++; // while balloons intervals intersect, we can shoot them all by one arrow, so we only increase the result when a balloon out of the range occurs.
            }
            i++;
        }
        return res;
    }
};