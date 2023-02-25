//Author: Mohamed Gewaly
class Solution {
public:
    /** 
    We look at evne indicies and check if the number is equal to the number on its right.
    if not equal return this number at even index,
    else, the number is the last element.
    **/
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0]; // if there one element 
        for(int i=0;i<nums.size()-1;i+=2){   
            if(nums[i]!=nums[i+1]) return nums[i]; // if not equal return this number at even index,
        }

        return nums[nums.size()-1]; // the number is the last element. 
        
    }
};