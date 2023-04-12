// Author: Ahmed Gamal

// for this problem, we want to remove all the stars from the given string
// every star removes the previous character, so we can use a stack to keep track of the characters and remove the previous character if we encounter a star
// here, we can use a string as a stack to keep track of the characters

class Solution {
public:
    string removeStars(string s) {
        // string to keep track of the characters
        string ans;

        // traverse the string
        for(auto& i : s) {
            // if the current character is a star, remove the previous character
            if(i == '*') {
                // check if the string is not empty
                if(not ans.empty()) {
                    ans.pop_back();
                }
            } else {
                // otherwise, add the current character to the string
                ans += i;
            }
        }

        // return the string after removing the stars
        return ans;
    }
};