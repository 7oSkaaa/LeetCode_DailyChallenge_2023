//Author: Omar Salem
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int numOfFlips = 0 ;
        for(auto &c : s)
            numOfFlips += (c == '0') ;// 11111
        
        int MinOfFlips = numOfFlips ;
        for(auto &c :s)
        {
            if(c == '0')
                MinOfFlips = min(MinOfFlips , --numOfFlips) ;// return flips
            else
                ++numOfFlips;
        }
        return MinOfFlips;
    }
};