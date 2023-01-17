// Author: Noura Algohary
/*
ex1: 010101
  | ones  | flips | flips after if condition
0 |   0   |   1   |   0
1 |   1   |   0   |   0
0 |   1   |   2   |   1
1 |   2   |   1   |   1
0 |   2   |   3   |   2
1 |   3   |   2   |   2
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;

        for(char ch : s)
        {
            if(ch == '1')
            {
                ones ++;
            }else
            {
                flips++;
                if (ones < flips)
                    flips = ones;
            }
            
        }

        return flips;
    }
};