// Author: Noura Algohary
// no. of odd numbers between 2 numbers is (high - low) / 2
// if one of them is odd, then it counts
class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 != 0 || high % 2 != 0)
            return (high - low) / 2 + 1;
        else
            return (high - low) / 2;
    }
};