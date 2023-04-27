// Auhtor: Mahmoud Aboelsoud

class Solution {
public:
    int bulbSwitch(int n) {
        // for this problem we need to know how many light bulbs are on after n rounds
        // to know that you need to know for each light bulb to stay on at the end it needs to have odd number of divisors
        // the only numbers that have odd number of divisors are perfect squares
        // so the answer is the number of perfect squares less than or equal to n
        // which is sqrt(n)


        return sqrt(n);
    }
};
