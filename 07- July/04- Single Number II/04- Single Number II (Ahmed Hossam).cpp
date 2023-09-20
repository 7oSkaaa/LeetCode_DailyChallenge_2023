// Author: Ahmed Hossam

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Variable to store the single number
        int single = 0;

        // Loop through each bit position from 0 to 31
        for(int bits = 0, curr_bit = 0; bits < 32; bits++, curr_bit = 0) {
            // Iterate over each element in the vector
            for(auto& i : nums) {
                // Check if the current bit is set in the element
                if(i & (1ll << bits))
                    curr_bit++;
            }

            // Check if the count of the current bit is not a multiple of 3
            if(curr_bit % 3 == 1)
                // Set the corresponding bit in the single variable
                single |= (1 << bits);
        }

        // Return the single number
        return single;
    }
};
