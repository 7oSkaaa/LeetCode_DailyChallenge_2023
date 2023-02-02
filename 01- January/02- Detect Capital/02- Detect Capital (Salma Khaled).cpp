// Author: Salma Khaled
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0, sm=0;
        //count capital letters
       for(int i=0; i<word.size(); i++){
           if(word[i] >= 'A' && word[i] <= 'Z'){
               cap++;
           }
       }
       // count small letters
       for(int i=0; i<word.size(); i++){
           if(word[i] >= 'a' && word[i] <= 'z'){
               sm++;
           }
       } 
       // if all letters are capital
       if(cap == word.size()){
           return true;
       }
       //if all letters are small
       else if(sm == word.size()){
           return true;
       }
       // if the first letter is capital and the rest are small
       else if(cap == 1 && word[0] >= 'A' && word[0] <= 'Z'){
           return true;
       }
       return false;
    }
};