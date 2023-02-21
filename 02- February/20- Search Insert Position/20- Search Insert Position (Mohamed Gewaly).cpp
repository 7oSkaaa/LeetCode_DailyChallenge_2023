// Author : Mohamed Gewaly
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
   // loop over the elements twice 
  // 1-first, if the target is found
 //  2-second, if not found && not the last element  
//   3-else(the target greater than all elements) 
        //return the last index      
        
      for(int i=0;i<nums.size();i++){
          if(nums[i]==target){ //if the target is found
              return i;
          }
      }  
        // if not found && not the last element 
     for(int i=0;i<nums.size();i++){
         if(nums[i]>target) return i; 
         
     }
        // if not found && the last element 
        return nums.size();
    }
};