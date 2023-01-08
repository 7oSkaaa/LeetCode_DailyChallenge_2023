class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    /*
    Approach :-
    -> as any two points (x1,y1),(x2,y2) can make a line with   slope : (y2-y1)/(x2-x1)
    -> we get the slope between each two points then calculate the maximum repeated slope
    */
    int n = points.size();
    int res = 1;
    double sl = 0;
    for (int i = 0; i < n - 1; i++)
    {
      unordered_map<double, int> slope; // stores frequency of slopes
      for (int ii = i + 1; ii < n; ii++)
      {
        // vertical points
        if (points[i][0] == points[ii][0])
          // assumed (-1e9) to be the value
          // +1 in max function as the point (point[i][0],point[i][1]) --> has same (x) value
          slope[-1e9]++, res = max(res, slope[-1e9] + 1);
        else
        {
          // delta(y) / delta(x)
          sl = (double)(points[ii][1] - points[i][1]) / (double)(points[ii][0] - points[i][0]);
          slope[sl]++;
          res = max(res, slope[sl] + 1);
          // +1 in max function as the point (point[i][0],point[i][1]) --> one the same line
        }
      }
    }
    return res;
  }
};