Author: Anas Maher

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntr=0, n=word.size(); // cntr = counter of upper letters.

        for(char i : word) if(isupper(i)) cntr++;

        // all letters are upperCase or all are lowerCase or (only one is upper and its the first one in the word).
        if(cntr==n || cntr==0 || (cntr==1 && isupper(word[0]))) return true;
        else return false;
    }
};