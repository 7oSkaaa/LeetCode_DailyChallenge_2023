//Author: Mohamed Ibrahim

class Solution {
public:
    int tribonacci(int n) {
         // store the first 3 numbers in the vector.
        vector<int> v = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            // the new number is the sum of the last 3 numbers.
            v[i%3] = v[(i-1) % 3] + v[(i-2) % 3] + v[(i-3) % 3];
        }
        // return the N-th tribonacci number
        return v[n%3];
    }
};
