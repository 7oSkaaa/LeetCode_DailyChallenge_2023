// Author : Hazem Elakbawy
class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    std::unordered_map<char, string> mp1;
    std::unordered_map<string, char> mp2;
    vector<string> words;

    string str = "";
    // split words into separate vector
    for (int i = 0; i < s.size(); i++)
      s[i] == ' ' ? words.push_back(str), str = "" : str += s[i];
    // add any remaining words
    words.push_back(str);

    if (pattern.size() != words.size())
      return false;

    // check if each letter maps to a specific word (and vice versa)
    for (int i = 0; i < pattern.size(); i++)
    {
      auto it1 = mp1.find(pattern[i]);
      if (it1 == mp1.end())
        mp1[pattern[i]] = words[i];
      else if (it1->second != words[i])
        return false;

      auto it2 = mp2.find(words[i]);
      if (it2 == mp2.end())
        mp2[words[i]] = pattern[i];
      else if (it2->second != pattern[i])
        return false;
    }

    return true;
  }
};