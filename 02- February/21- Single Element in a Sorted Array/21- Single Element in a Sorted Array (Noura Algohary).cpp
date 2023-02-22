// Author: Noura Algohary
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high)
        {
            int mid = (low + high) / 2;

            if(mid % 2 !=0)
            {
                mid--;
            }
            // if the single element is on the left side 
            if(nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }else
                high = mid;
        }
        return nums[high];
    }
};