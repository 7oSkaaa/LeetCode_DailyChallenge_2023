// Author : Hazem Elakbawy
class Solution
{
public:
  int minimumRounds(vector<int> &tasks)
  {
    long long res = 0;
    map<int, int> mp;
    for (int i : tasks) // frequency of all tasks periods
      mp[i]++;
    for (auto it : mp)
    {
      int n = it.second, x = n % 3;
      if (x == 1)
      {
        if (n == 1)
          return -1;
        else if (n == 4)
          res += (n / 2);
        else
          res += ((n - 4) / 3 + 2); // 16  = 12 + 4 ==> 12/3 + 4/2 ==>  4 + 2 (6)
      }
      else if (x == 2)
      {
        if (n == 2)
          res += 1;
        else
          res += ((n - 2) / 3) + 1; // 14 = 12 + 2  ==> 12/3 + 2/2  ==> 4 + 1 (5)
      }
      else
        res += (n / 3); // 12 ==> 12/3 ==> (4)
    }
    return res;
  }
};