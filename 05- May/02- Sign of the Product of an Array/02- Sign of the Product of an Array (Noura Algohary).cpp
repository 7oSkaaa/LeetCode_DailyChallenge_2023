// Author: Noura Algohary
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int signCounter = 0;

        for(int num : nums)
        {
            // if one zero appears, the result is zero
            if(num==0)
                return 0;
            else if(num<0)
                signCounter++;
        }

        // if negative numbers are of odd count, the result is negative
        if (signCounter%2==0)
            return 1;
        else
            return -1;
    }
};