// Author: Ahmed Hossam

class Solution {
public:
    int tribonacci(int n) {
        // store the tribonacci numbers
        vector < int > trib(n + 5);

        // initialize first three terms
        trib[0] = 0, trib[1] = 1, trib[2] = 1;

        // trib[i] will be the summation of the last three terms
        for(int i = 3; i <= n; i++)
            trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];

        // the N-th tribonacci number
        return trib[n];

    }
};
