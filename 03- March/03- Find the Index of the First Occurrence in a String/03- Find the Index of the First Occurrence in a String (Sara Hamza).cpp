//Author: Sara Hamza

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        //edge cases
        if(needle == haystack)
            return 0;

        if(haystack.size() < needle.size())
            return -1;

        //Sliding Window => s
        string s = "";


        //first window
        int i = 0;
        for(; i < n; ++ i){
            s += haystack[i];
        }

        for(; i < m; ++i){
            //check if it is the current window
            if(s == needle)
                return i - n;

            //continue sliding the window
            //pop one char from left and append a new one to the right
            s = s.substr(1);
            s += haystack[i];
        }

        //last window check
        if(s == needle)
            return i - n;

        return -1;
    }
};
