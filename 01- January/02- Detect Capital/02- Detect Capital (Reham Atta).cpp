// Author: Reham Atta

class Solution {
public:
    // comparing with first two characher in word
    bool detectCapitalUse(string word) {
    bool ok=true;
    if(!word.empty()) 
    {
        // if the first & the second are upper then check is all letters are upper or not
        if(isupper(word[0]) && isupper(word[1]))
        {
            for(int i=2;i<word.size();i++) 
            {
                if(!isupper(word[i])) ok=false;
            }
        }
        // if the first is upper & the second is lower then check is all letters are lower or not
        else if(isupper(word[0]) && !isupper(word[1]))
        {
            for(int i=1;i<word.size();i++)
            {
                if(!islower(word[i])) ok=false;
            }
        }
        // if the first is lower then check is all letters are lower or not
        else if(islower(word[0]))
        {
            for(int i=1;i<word.size();i++)
            {
                if(!islower(word[i])) ok=false;
            }
        }
    }
    return ok;
  } 
};