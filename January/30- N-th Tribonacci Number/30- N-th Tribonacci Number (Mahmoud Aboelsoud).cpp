// Author: Mahmoud Aboelsoud

class Solution {
public:
    int tribonacci(int n) {
        // to calculate the n-th tribonacci number
        // we only need the last 3 numbers
        // so we can use a vector of size 3
        // and use the mod operator to get the last 3 numbers
        // and the mod operator will also help us to get the n-th number
        
        // store the first 3 numbers in the vector 0, 1, 1;
        vector<int> v = {0, 1, 1};
        
        // loop from 3 to n 
        for(int i = 3; i <= n; i++)
            // store the new number in i % 3 index in the vector
            // the new number is the sum of the last 3 numbers
            // which are the numbers in the (i - 1) % 3, (i - 2) % 3, (i - 3) % 3 indexes
            // in the vector
            v[i % 3] = v[(i - 1) % 3] + v[(i - 2) % 3] + v[(i - 3) % 3];

        // return the n-th number which is in the n % 3 index in the vector
        return v[n % 3];
    }
};
