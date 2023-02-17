//Author: Mohamed Ashraf

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0 , zeros = 0, cnt = 0;
        for(auto i : s){
            if(i == '1')   ones++;
            else if(ones > 0) zeros++;

            if(ones <= zeros) // flips this ones in this part and reset the conuter (ones , zeros)
                cnt += ones , ones = 0 , zeros = 0;
        }
        //  added the last part
        cnt += min(ones , zeros);
        return cnt;
    }
};