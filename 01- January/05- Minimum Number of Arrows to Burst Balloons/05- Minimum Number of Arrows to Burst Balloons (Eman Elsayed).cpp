// Author : Eman Elsayed

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // Size of points to iterate over it
        int n = points.size();
        int cnt = 0; // Keep it to count minimum number of arrows

        // Sort the balloons by their y-coordinates.
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b)
             { return (a[1] < b[1]); });
        // since we sorted our intervals -> either they interscted or not
        // iterate over the values and check for how many can you actually burst.
        for (int i = 0; i < n; i++)
        {
            int tmp = points[i][1];

            while (i + 1 < n && tmp >= points[i + 1][0]) // -> intersected
            {
                i++;
            }
            // to count after create a new merged interval or if the intervals are separated
            cnt++;
        }

        // Return the Answer of the Problem
        return cnt;
    }
};