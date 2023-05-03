// Author: Mazen Alasas
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int numberOfNegativeNumbers = 0;  // To hold the number of negative numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)  // If there is a single zero
                return 0;   // It will make the product of the multiplication zero
            if (nums[i] < 0)   // If there are negative numbers هt will affect the product of the multiplication by their number
                numberOfNegativeNumbers++; // So I will count their number
        }
        /* If the number of negative numbers is odd (numberOfNegativeNumbers % 2 == 1) it will return -1 because the product will be negative and vice versa
           if it is even (numberOfNegativeNumbers % 2 == 0) it will return 1 because the product will be positive */
        return numberOfNegativeNumbers % 2 ? -1 : 1; 
    }
};
