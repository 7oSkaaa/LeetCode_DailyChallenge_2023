// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(auto i:nums){
            // if there any element equal to zero 
            //then return zero
            if(i==0){
                return 0;
            }
            // check if current number is negative
            if(i<0){
                neg++;
            }
        }
        // if number of negative numbers is odd then the product will be negative
        // if number of negative numbers is even then the product will be positive
        return (neg%2==0?1:-1);
    }
};
