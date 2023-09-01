// Author:  Esraa Syam
class Solution {
public:
    vector<int> countBits(int n) {
        vector < int > v;
        for(int i = 0 ; i <= n ; i++){
            // __builtin_popcount(i) returns the number of 1's in the binary representation of i.
            v.push_back( __builtin_popcount(i));
        }
        return v; // return the vector
    }
};