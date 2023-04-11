// Author: Mahmoud Aboelsoud

class Solution {
public:
    string removeStars(string s) {
        // each star removes the last character in the string

        // initialize an empty string
        string ans = "";
        // loop over the string
        for(auto&i: s){
            // if the current character is a star remove the last character in the string
            if(i == '*') ans.pop_back();
            // else add the current character to the string
            else ans += i;
        }

        // return the ans string
        return ans;
    }
};
