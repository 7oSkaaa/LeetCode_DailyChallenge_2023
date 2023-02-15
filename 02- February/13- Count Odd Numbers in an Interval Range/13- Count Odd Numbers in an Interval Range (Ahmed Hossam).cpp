// Author: Ahmed Hossam

class Solution {
public:
    int countOdds(int low, int high) {
        // count odd number in range from 1 to x
        auto count_odd = [&](int x){
            return (x + 1) / 2;
        };

        // number of odd from l to r will be number of odd from [1 to r] - number of odd from [1 to l - 1]
        return count_odd(high) - count_odd(low - 1);
    }
};
