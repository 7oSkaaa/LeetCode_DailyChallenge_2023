
// Auther: Reham Atta

class Solution {
public:

    // first store the string word in vector 
    // solve it using two map 
    // chartoword to store letters that related with word
    // wordtochar to store words that related with letters
    // iterate over the element and push them into maps

    bool wordPattern(string pattern, string s) {
    string t="";
    vector<string>v;
    for(auto it : s) {
        if(it != ' '){
            t+=it;
        }
        else{
            v.push_back(t);
            t="";            
        }    
    } v.push_back(t);

    if(v.size() != pattern.size()) return 0;

      map<string,char>wordtochar;
      map<char,string>chartoword;

    for(int i=0;i<pattern.size();i++)
    {
       if(chartoword.count(pattern[i])) 
       {
           if(chartoword[pattern[i]] != v[i]) 
           {
               return false;
           }
       }
       if(wordtochar.count(v[i])) 
       {
           if(wordtochar[v[i]] != pattern[i])
           {
               return false;
           }
       }
       chartoword[pattern[i]] = v[i];
       wordtochar[v[i]] = pattern[i];
    }
    return true;
  }
}; 