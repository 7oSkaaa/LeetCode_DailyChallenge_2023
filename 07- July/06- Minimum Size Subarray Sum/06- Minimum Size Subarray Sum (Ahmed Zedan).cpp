// author : Ahmed Zedan
class Solution {
public:
    // sliding window approach
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() , l=0 , r=0 , ans = INT_MAX , sum = 0 ;

        while(r<n){
            sum += nums[r++] ;
            
            // while sum >= target decresee left pointer and update answer
            while(sum>=target){
                ans = min(ans , r-l) ; 
                sum -= nums[l++] ; 
            }

        }

        // if ans == INT_MAX that's main no exsit any subarray sum >= target 
        return (ans==INT_MAX ? 0 : ans) ;  
    }
};