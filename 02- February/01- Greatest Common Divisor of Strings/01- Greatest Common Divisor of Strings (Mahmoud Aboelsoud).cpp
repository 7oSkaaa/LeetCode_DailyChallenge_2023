// Author: Mahmoud Aboelsoud

class Solution {
public:
    // to find the greatest common divisor of two strings
    // we start by building a substring of the second string starting from the first character and increasing the length by one
    // then we check if we can concatenate the substring to the first string and the second string
    // if we can, then we update the answer with the substring and continue building the substring by increasing the length by one and checking again
    // because we want the largest substring that satisfies the condition


    // function to check if we can concatenate the current substring to build the first string and the second string 
    bool check(string& s, string& k){
        // if the length of the string is not divisible by the length of the substring, then we can't build the first string
        if(s.size() % k.size()) return 0;
        // 
        for(int i = 0; i < s.size(); i += k.size())
            // we check if the substring is equal to the current substring
            if(s.substr(i, k.size()) != k) return 0;

        return 1;
    }

    string gcdOfStrings(string str1, string str2) {
        // k is the current substring, ans is the answer
        string k = "", ans = "";
        for(int i = 0; i < str2.size(); i++){
            // we build the substring by adding the current character to the end of the substring
            k += str2[i];
            // if we can concatenate the substring to build the first string and the second string, then we update the answer with the substring
            // and continue building the substring by increasing the length by one and checking again
            // because we want the largest substring that satisfies the condition
            if(check(str1, k) && check(str2, k)) ans = k;
        }

        // if the answer is empty, then there is no common divisor
        // otherwise, the answer is the greatest common divisor of the two strings
        return ans;
    }
};
