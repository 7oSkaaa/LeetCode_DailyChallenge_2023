// author: Esraa Syam
class Solution {
public:
    #define ceil(a, b) ((a) + (b) - 1) / (b)
    int countOdds(int low, int high) {
        // get nearest odd number for low and high
        if(!(low & 1)) low++;
        if(!(high & 1)) high--;
        // to get the number of odd numbers between low and high
        // we need to get the number of even numbers between low and high and add 1
        return ceil(high - low + 1, 2);
    }
};