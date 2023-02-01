//Author: Mohamed Ibrahim

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        /*If the concatenation of str1 and str2 is not equal to the concatenation of str2 and str1,
        then there is no common divisor*/
        if (str1 + str2 != str2 + str1) return "";
        /*Otherwise, the gcd of the two strings is equal to the gcd of their lengths
        The result can be obtained by extracting a substring of the longer string with a length equal to the gcd of their lengths*/
        return str1.substr(0, __gcd(str1.size(), str2.size()));
    }
};