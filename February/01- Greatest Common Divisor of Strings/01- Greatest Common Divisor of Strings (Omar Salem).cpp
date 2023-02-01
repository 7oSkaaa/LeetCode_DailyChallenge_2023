//Author : Omar Salem
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    //if concatenate of str1 + str2 == str2 + str1 then we can divide string 
        string a = str1+str2 , b = str2+str1; //concatenation of string 
        return (a == b)?str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};