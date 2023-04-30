// Author: Noura Algohary

class Solution {
public:
    int bulbSwitch(int n) {
        // bulbs are counted (turned on) when it have odd number of divisors
        // only numbers with perfect square roots have odd divisors
        // to count the number of perfect square roots in n,
        // it must be equal to sqrt(n)
        return sqrt(n);
    }
};