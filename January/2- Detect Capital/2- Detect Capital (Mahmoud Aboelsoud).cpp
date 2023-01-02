// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt_cap = 0;
        
        // count capital characters in the word
        for(auto&i: word){
            if(isupper(i)) cnt_cap++;
        }

        // check the cases that define the right usage of capitals:
        //   1- all letters are capitals
        //   2- all letters are small
        //   3- only the first letter is capital    
        if(cnt_cap == 0 || cnt_cap == word.size()) return true;
        else if(cnt_cap == 1 && isupper(word[0])) return true;


        // return false otherwise
        return false;
    }
};
