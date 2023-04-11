// Author: Ahmed Hossam

class Solution {
public:
    string removeStars(const string& s) {
        string without_stars;

        //iterating over the string s
        for(auto& c : s){
            //if the current character is an asterisk, remove the last character from the answer string
            if(c == '*')
                without_stars.pop_back();
            //otherwise, add the current character to the answer string
            else
                without_stars += c;
        }
        
        //return the answer string without the asterisks
        return without_stars;
    }

};
