// Author : Hazem Elakbawy
class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    int cap = 0, n = word.size();
    for (int i = 0; i < n; i++)
      // count capital letters in word
      (word[i] >= 'A' && word[i] <= 'Z') ? cap++ : cap;
    // check the number of capital letters
    // valid capital use if :
    // no capital letters in the word (leetcode) ==> !cap
    // 1 capital letter (first one) (Leetcode)   ==> cap == 1 && word[0] >= 'A' && word[0] <= 'Z'
    // all letters are capital (LEETCODE)        ==> cap == n
    // otherwise (non-valid use)
    if ((!cap) || (cap == n) || (cap == 1 && word[0] >= 'A' && word[0] <= 'Z'))
      return true;
    else
      return false;
  }
};