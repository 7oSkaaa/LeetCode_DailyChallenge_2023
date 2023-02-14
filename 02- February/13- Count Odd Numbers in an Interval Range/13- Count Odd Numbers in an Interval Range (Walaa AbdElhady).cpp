// Author: WalaaAbdElhady

class Solution {
public:
    int countOdds(int low, int high) {
        // (number of odd from 1 to high) - (number of odd from 1 to low - 1)
        return (high + 1) / 2 - low / 2;
    }
};