// Author: Ahmed Gamal

// for this problem, we can achieve the desired result by just using the lower_bound function
// the lower_bound function returns an iterator to the first element in the range [first, last) that is not less than (i.e. greater or equal to) value, or last if no such element is found
// so we can just return the difference between the iterator returned by the lower_bound function and the begin iterator of the vector (the index of the first element in the range [first, last) that is not less than (i.e. greater or equal to) value)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};