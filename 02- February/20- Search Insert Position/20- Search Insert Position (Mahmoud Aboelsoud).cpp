// Author: Mahmoud Aboelsoud

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower bound returns the first element that is not less than target 
        // so if the target is not in the vector, it will return the first element that is greater than target
        // so we subtract the begining of the vector from the lower bound to get the index of the first element that is greater than or equal the target
        // which will be the index to insert the target in the vector to keep the vector sorted


        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
