// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // let's use binary search to get the correct index in O(log(n))
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            // get the mid index
            mid=(l+r)/2;
            // check if it equal to target
            if(nums[mid]==target){
                return mid;
            }
            // else update the range
            else if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
