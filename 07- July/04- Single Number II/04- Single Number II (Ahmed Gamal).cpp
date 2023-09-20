// Author: Ahmed Gamal

// for this problem, we can use a greedy approach
// since every number appears 3 times except for one number, all the bits in all numbers will appear number of times divisible by 3 except for the bits in the number that appears once
// so we can count the number of times each bit appears in all numbers
// then we can check if the number of times each bit appears is divisible by 3 or not
// if it is not divisible by 3, then this bit is in the number that appears once and we can add it to the answer

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // freq[i] is the number of times the ith bit appears in all numbers
        vector<int> freq(32);

        // count the number of times each bit appears in all numbers
        for(auto& x : nums) {
            for(int bit = 0; bit < 32; bit++) {
                if(x & (1 << bit)) {
                    freq[bit]++;
                }
            }
        }

        // ans is the number that appears once
        int ans = 0;
        for(int bit = 0; bit < 32; bit++) {
            // if the number of times the bit appears is not divisible by 3, then this bit is in the number that appears once
            if(freq[bit] % 3) {
                ans |= 1 << bit;
            }
        }
        
        return ans;
    }
};