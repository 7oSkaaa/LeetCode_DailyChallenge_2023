// Author: Ahmed Gamal

// for this problem, we need just to implement what the problem asks us to do
// we can use the find function from the string class to solve this problem in O(n) time complexity and O(1) space complexity
// the find function returns the index of the first occurrence of the given string in the current string
// if the given string is not found, it returns string::npos

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }
};