// Author : Hazem Elakbawy
class Solution
{
public:
  int minDeletionSize(vector<string> &strs)
  {
    int m = strs[0].size(), n = strs.size();
    int res = 0;
    bool sorted = 1;
    for (int i = 0; i < m; i++) // columns
    {
      for (int ii = 1; ii < n; ii++) // rows
      {
        // check if above letter is bigger than current
        if (strs[ii][i] < strs[ii - 1][i])
        {
          sorted = 0;
          break;
        }
      }
      if (!sorted)
        res++, sorted = 1;
    }
    return res;
  }
};