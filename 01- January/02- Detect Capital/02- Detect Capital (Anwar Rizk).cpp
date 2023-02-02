// Author: Anwar Rizk

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        // count all Upper Case chars in 'word' using builtin function 'isupper()'
        for(auto& i : word) cap += (isupper(i) ? 1 : 0);
        // if entire word consist of Uppercase chars or Lowercase return true
        if(cap == word.size() || !cap) return true;
        // otherwise if there is only one character Uppercase
        // it must be at front of 'word'
        if(cap == 1) return isupper(word[0]);
        // if there are some chars Uppercase not entire 'word'
        // and all above conditions not met return false
        return false;
    }
};
