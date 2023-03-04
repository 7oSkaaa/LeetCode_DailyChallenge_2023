// Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
        - all we need is to find the first index from which there's a substring identical to needle
        - We can use find func to see whether haystack contains that substring or not:
                                                        * If so, it'll return the first index where that substring first occurred
                                                        * Otherwise, it returns -1 ~ "string::npos"
    */
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};
