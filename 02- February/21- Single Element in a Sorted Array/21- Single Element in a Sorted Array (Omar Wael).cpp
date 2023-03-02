// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // binary search on the vector till you find such element
        // every step you should calculate if you should go left or right 
        // if current index is even so just compare to previous element
        // if current index is odd so just compare to next element
        // if one of the above condeitions satisfied then go right
        // else go left
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
};
