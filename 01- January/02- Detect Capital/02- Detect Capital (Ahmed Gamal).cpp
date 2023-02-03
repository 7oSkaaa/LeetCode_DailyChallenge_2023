// Author: Ahmed Gamal

class Solution {
public:
    bool detectCapitalUse(string word) {
        // check if the first character is an uppercase letter
        bool first = isupper(word.front());
        int cnt = 0;

        // count the number of uppercase letters in the string
        for(auto& c : word){
            cnt += isupper(c) != 0;
        }

        // if there are some uppercase letters
        if(cnt){
            // the conditions are satisfied only if:
                // 1 - there's only one uppercase letter and it is the first of the string
                // 2 - the whole string is in uppercase (count of uppercase letters equals the size of the string)
            return cnt == word.size() or (cnt == 1 and first);
        }

        // there are no uppercase letters
        return true;
    }
};