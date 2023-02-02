// author: Esraa Syam
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // base case
        if(str1 == str2) return str1;
        // recursive case
        // if str1 is shorter than str2, swap them
        if(str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        // if str2 is not a substring of str1, return ""
        if(str1.substr(0, str2.size()) != str2) return "";
        // if str2 is a substring of str1, remove str2 from str1 and call gcdOfStrings again
        // with the new str1 and str2
        // str1.substr(str2.size()) returns the remaining part of str1 after removing str2
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};