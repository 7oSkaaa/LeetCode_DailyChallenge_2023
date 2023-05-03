// Author : Ibrahim Khalid 
class Solution {
public:
    int arraySign(vector<int>& nums) {
        // to count negative numbers
         int neg=0;
        for(int i=0;i<nums.size();i++){
            // if equal 0 return 0;
          if(nums[i]==0){
              return 0;
          }
          else if(nums[i]<0){
              neg++;
          }
        }
        // if numbers of negative numbers is even then x is positive 
        if(neg%2==0){
            return 1;
        }
    // else 
        return -1;
    }
};
