// Author: Ahmed Gamal

// for this problem, we want to find if the target exists in the array or not
// as the array is sorted, we can use binary search to solve this problem (standard binary search)
// but we can also use upper_bound to solve this problem
// upper_bound returns an iterator to the first element that is greater than the target
// if the target exists in the array, then the iterator will point to the element that is right after the target
// so we can check if the element before the iterator is the target or not

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(), nums.end(), target);
        
        if(it != nums.begin()) {
            it = prev(it);
        }

        return (*it == target ? it - nums.begin() : -1);
    }
};

// we can also do it using binary search and lower_bound like this:
// return binary_search(nums.begin(), nums.end(), target) ? lower_bound(nums.begin(), nums.end(), target) - nums.begin() : -1;