// Author: Mahmoud Aboelsoud

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // we have a sorted array with all elements appearing twice except one
        // let's assume that every element appears twice that means that each element appears at two positions adjecent to each other
        // one of the two positions first one is even and the other one is odd (our array is 0-based)
        // having an element that appears only once means that it will mess up the pattern of the array after it's appearance 
        // so we can use binary search to find the element that messes up the pattern

        // if the array has only one element then it's the only element that appears once
        if(nums.size() == 1) return nums[0];

        // the bounds of the array that we will search in it
        int l = 0, r = nums.size() - 1;
        // we will stop when r > l
        while(l <= r){
            // the middle of the array
            int m = l + (r - l)/ 2;
            if(m & 1){
                // if the middle is odd and the element before it is the same as the middle element then the element that appears once is after the middle element
                if(nums[m] == nums[m - 1]) l = m + 1;
                // else the element that appears once is before the middle element
                else r = m - 1;
            }
            else{
                // if the middle is even and the element after it is the same as the middle element then the element that appears once is after the middle element
                if(nums[m] == nums[m + 1]) l = m + 1;
                // else the element that appears once is before the middle element
                else r = m - 1;
            }
        }
        
        // the element that appears once is the element at the left bound
        return nums[l];
    }
};
