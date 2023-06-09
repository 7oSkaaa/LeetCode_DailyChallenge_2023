// Author: Ahmed Gamal

// to solve this problem we loop over all bits in the numbers a, b, c
// for each bit, if we need to set it to 1, then we need to flip it in one of the numbers a, b
// if we need to set it to 0, then we need to flip it in both numbers a, b

// this is because we are using the OR operation

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // ans: number of flips needed
        int ans = 0;
        
        // loop over all bits
        for(int bit = 0; bit < 32; bit++) {
            // p: mask to get the bit at position bit
            int p = 1 << bit;

            // if the current bit in c is different from the current bit in (a | b)
            if((c & p) ^ ((a | b) & p)) {
                // if we need to set the current bit to 0
                if(not(c & p)){
                    // if the current bit in a is 1, then we need to flip it
                    // if the current bit in b is 1, then we need to flip it
                    ans += !!(a & p) + !!(b & p);
                } else {
                    // if we need to set the current bit to 1
                    // we need to flip it in one of the numbers a, b
                    ans += !((a & p) | (b & p));
                }
            }
        }

        return ans;
    }
};