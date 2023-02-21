//Author: Walaa AbdElhady

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // search space of bs
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            // check if this number is the answer or not
            if (valid(md, nums)) return nums[md];
            //if the number is not the answer we need to know if we should move to the left or the right
            // so we must calculate the leftSize and if the size is odd => there is a number appears exactly once => move left
            // else move to right
            int leftSize = (nums[md] == nums[md - 1]) ? md - 1 : md;
            if (leftSize & 1)r = md - 1;
            else l = md + 1;
        }
        return -1;
    }
    // function to check if the number is different from left and right number
    // and also if the number is the first and different from the right number or if the number is the last and different from the left number return true
    bool valid(int idx, vector<int>& nums) {
        return ((idx - 1 < 0 || nums[idx] != nums[idx - 1]) && (idx + 1 >= nums.size() || nums[idx] != nums[idx + 1]));
    }
};