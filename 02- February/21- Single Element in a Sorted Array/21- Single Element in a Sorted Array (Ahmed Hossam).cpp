// Author: Ahmed Hossam

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // a ^ a = 0 
        // so each element will enter twice will be zero so the remaining answer will be the number that appears odd times
        int xr = 0;
        for(auto& i : nums)
            xr ^= i;
        return xr;
    }
};
