// Author: Mahmoud Aboelsoud

class Solution {
public:
    int arraySign(vector<int>& nums) {
        // to find the sign of the product of the array we need to know the parity of the negative number and if we have zero or not
        // if we have zero the product will be zero
        // if not we need to know the parity of the negative numbers
        // if we have odd number of negative numbers the product will be negative
        // else the product will be positive

        // parityOfNegative: 0 -> even number of negative numbers, 1 -> odd number of negative numbers
        int parityOfNegative = 0;

        // loop over the array
        for(auto&i: nums){
            // if we have zero the product will be zero
            if(i == 0) return 0;
            
            // if we have negative number we need to change the parity of the negative numbers
            // we can do that by xoring the parity with 1
            if(i < 0) parityOfNegative ^= 1;
        }

        // if we have odd number of negative numbers the product will be negative else the product will be positive
        return (parityOfNegative ? -1 : 1); 
        
    }
};
