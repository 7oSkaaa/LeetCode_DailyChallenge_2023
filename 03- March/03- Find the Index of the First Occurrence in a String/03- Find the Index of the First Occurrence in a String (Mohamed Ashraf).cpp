// Author: Mohamed Ashraf

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size_needle = needle.size();
        int size_haystack = haystack.size();
        for(int i = 0; i + size_needle <= size_haystack; i++){
            // Given to str for index (i) to (i + size_needle)
            string str = haystack.substr(i , size_needle);
            // Check for string str is the same needle
            if(str == needle) return i;
        }
        // if (needle) is not found
        return -1;
    }
};
