// Author : Hazem Elakbawy
class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    int cap = 0, n = word.size();
    for (int i = 0; i < n; i++)
      (word[i] >= 'A' && word[i] <= 'Z') ? cap++ : cap;
    if ((!cap) || (cap == n) || (cap == 1 && word[0] >= 'A' && word[0] <= 'Z'))
      return true;
    else
      return false;
  }
};