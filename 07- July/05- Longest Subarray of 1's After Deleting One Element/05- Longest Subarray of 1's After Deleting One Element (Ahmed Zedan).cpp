// author : Ahmed Zedan
class Solution {
public:
    // sliding window approach
    int longestSubarray(vector<int>& nums) {
        int one = 0 , zero = 0 , l = 0 , r = 0 , ans = 0 , n = nums.size() ; 

        while(r<n){

            one += (nums[r]) ;  // count of ones
            zero += (nums[r]==0) ; // count of zeros
            r++ ; // increase the window size
            while(zero>1){
                zero -= (nums[l]==0) ; // decrease the count of zeros
                one -= (nums[l]) ; // decrease the count of ones
                l++ ; // decrease the window size
            }
            if(one)  ans = max(ans , r-l-1) ; 
            // if there is atleast one 1 in the window then update the ans
        }
        return ans ; 
    }
};