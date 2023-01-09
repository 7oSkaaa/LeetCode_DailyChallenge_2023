// Author: Abrar mohamed

class Solution {
// check if the both character are lowercase 
    bool is_lower(char ch) {
        return ch >='a' && ch <='z';
    }
// check if the both character are uppercase
    bool is_upper(char ch) {
        return ch >='A' && ch <='Z';
    }
// check if the character lowercase or uppercase
    bool is_alpha(char ch) {
        return is_lower(ch) || is_upper(ch);
    }
public:
    bool detectCapitalUse(string word) {
        bool all_upper = true, all_lower = true, first = is_upper(word[0]);
        for(int i=1; i<word.size(); i++) {
            if (is_lower(word[i])) all_upper = false;
            if (is_upper(word[i])) all_lower = false;
        }
        return all_lower || first && all_upper; 
    }
};