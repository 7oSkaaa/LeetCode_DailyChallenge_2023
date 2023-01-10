// Author: Omar Wael

class Solution {
public:
    bool detectCapitalUse(string word) {
        // variables to count small letters, capital letters and save position of the last capital char
        int cap=0,small=0,pos;
        for(int i=0;i<word.size();i++){
            // check whether this letter is small or capital
            if(word[i]>='a' && word[i]<='z'){
                small++;
            }else{
                cap++;
                // save last index that have capital letter
                pos=i;
            }
        }
        // check if the all letters are small or
        // all letters are capital or
        // all letters are small except one and it the first one
        if(small==word.size() || cap==word.size() || (cap==1 && pos==0)){
            return true;
        }
        return false;
    }
};