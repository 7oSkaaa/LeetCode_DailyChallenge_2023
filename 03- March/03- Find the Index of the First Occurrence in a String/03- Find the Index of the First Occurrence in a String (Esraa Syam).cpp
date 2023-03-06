// author: Esraa Syam
class Solution {
public:
    int strStr(string haystack, string needle) {
        // if needle is found in haystack, return the index of the first character of the first match
        // otherwise, return -1
        if(haystack.find(needle) != string::npos) 
            return haystack.find(needle); 
        else
            return -1;
    }
};