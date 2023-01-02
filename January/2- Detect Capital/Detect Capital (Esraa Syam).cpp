// Author: Esraa Syam
class Solution {
public:
    bool detectCapitalUse(string word) {
      // get a copy from the word to make it in upper case and another copy to make it in a lower case to compare it withe original
        string capital = word , small = word , ok ;
        transform(capital.begin() , capital.end() , capital.begin() ,::toupper);
        transform(small.begin() , small.end() , small.begin(), ::tolower);
      // get a copy from a word in lower case and make the first char in a upper case to compare it also
        ok = small;
        ok[0] = toupper(ok[0]);
      // compare the 3 cases that will return true 
        if(word == small or word == capital or word == ok) return true;
        return false;
    }
};
