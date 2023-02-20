//Author: Sara Hamza

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
            lower_bound returns an iterator pointing to the first element
            in nums which has a value not less than target. (equal or greater than target)
        */
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    }
};
