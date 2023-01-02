//Author: Nayra Mohammed 

#define sz(s) (int(s.size()))
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cnt = 0;
        for(auto c : word)
          cnt += (c <= 'Z'); /* All characters are alphabetic (uppercase or lowercase)
                       thus, we can find that  'a','b',....,'z' in ASCII have a bigger value 
                             than 'A','B',...'Z' so we can assure our character is uppercase
                             if and only if it has a value less than or equal 'Z'
                             */  

     
        if(!cnt || cnt == sz(word)) return 1; // no uppers or the whole string is uppercase 

        return (cnt == 1 && word[0] <= 'Z');//having one uppercase,the first character.        
    }
};
