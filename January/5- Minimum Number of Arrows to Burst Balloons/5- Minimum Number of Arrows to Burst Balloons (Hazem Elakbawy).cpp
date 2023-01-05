class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int n = points.size();
    sort(points.begin(), points.end());
    // sort on start points then by end
    // since we sorted our intervals ==> either they overlap or they are separated
    // overlap condition : end of previous interval >= start of current interval
    // otherwise : not intersected
    int res = 1;
    int prev = points[0][1];
    for (int i = 1; i < n; i++)
    {
      if (prev < points[i][0]) // not intersected
        res++, prev = points[i][1];
      prev = min(prev, points[i][1]);
    }
    return res;
  }
};