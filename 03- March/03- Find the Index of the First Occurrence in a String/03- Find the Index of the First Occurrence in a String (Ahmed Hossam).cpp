// Author: Ahmed Hossam

class Solution {
public:
    int strStr(string haystack, string needle) {
        // just use find builtin function
        int idx = haystack.find(needle);

        // string::npos means that we cannot find the subtring
        return (idx == string::npos ? -1 : idx);
    }
};
