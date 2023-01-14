// Author : Hazem Elakbawy
class Solution {
public:
  int arr[26];
  int find_(int c)
  {
    // function to return the root of union-find-ds
    if (c!=arr[c])
    {
      arr[c]=find_(arr[c]);
      return arr[c];
    }
    else
      return c;
  }
  void union_(int c1,int c2)
  {
    // get root of c1 & c2
    c1=find_(c1);
    c2=find_(c2);
    if (c1!=c2)
      // make sure that root is the smallest character
      (c1<c2)?arr[c2]=(c1):arr[c1]=(c2);
    return;
  }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // initialize each character in its group
        for(int i=0;i<26;i++)
          arr[i]=i;
        int n=s1.size();
        for(int i=0;i<n;i++)
          // union each pair of characters in both strings
          union_(s1[i]-'a',s2[i]-'a');
        string res="";
        for(char c:baseStr)
          // append root of each character (smallest)
          res+=char(find_(c-'a')+'a');
        return res;
    }
};