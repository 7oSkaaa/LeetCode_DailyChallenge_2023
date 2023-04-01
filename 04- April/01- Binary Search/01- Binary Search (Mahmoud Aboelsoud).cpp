// Author: Mahmoud Aboelsoud

class Solution {
public:
    // a wise man once said: Stop learning useless algorithms, go and solve some problems, learn how to use binary search.
  
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
