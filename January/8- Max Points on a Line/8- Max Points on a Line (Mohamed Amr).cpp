// Author: Mohamed Amr
// topics: Math, Greedy
class Solution {
public:
    // Function to calculate slope from two given points
    // return INF in case of perpendicular line.
    double slope(vector<int>&one, vector<int>&two)
    {
        if(two[0]-one[0] == 0)
            return INT_MAX;
        return (double)(two[1]-one[1])/(double)(two[0]-one[0]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
            return n;
        int ans = 0;
        // For every point in the vector, calculate how many other points have the same slope.
        // same slope with a certain point == lies on the same line with that point.
        for(int i=0; i<n; i++)
        {
            map<double, int>st;
            for(int j=0; j<n; j++)
            {
                if(i==j || points[i]==points[j])        continue;
                double m = slope(points[i], points[j]);
                st[m]++;
                ans = max(ans, st[m]);
            }
        }
        return ans+1;
    }
};