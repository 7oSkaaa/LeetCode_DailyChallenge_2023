// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search on the vector 
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            //get the middle of the current range
            mid=(l+r)/2;
            // if it equal the target return mid
            if(nums[mid]==target){
                return mid;
            }
            // if middle element if greater than target update range
            // ignore right part
            else if(nums[mid]>target){
                r=mid-1;
            }
            // if middle element if less than target update range
            // ignore left part
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};
