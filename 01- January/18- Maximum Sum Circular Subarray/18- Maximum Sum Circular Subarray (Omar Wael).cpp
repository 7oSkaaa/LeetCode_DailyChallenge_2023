// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=nums[0];
        int maxsum[nums.size()];
        int minsum[nums.size()];
        int mn=nums[0],mx=nums[0];
        maxsum[0]=nums[0];
        minsum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            // find which is best (add last element from maxsum to this element from nums or just take this element from nums)
            maxsum[i]=max(maxsum[i-1]+nums[i],nums[i]);
            // find which is least (add last element from minsum to this element from nums or just take this element from nums)
            minsum[i]=min(minsum[i-1]+nums[i],nums[i]);
            // calculate sum of nums vector
            sum+=nums[i];
            // update max and min sum
            mx=max(mx,maxsum[i]);
            mn=min(mn,minsum[i]);
        }
        // check if min not equal sum 
        // to avoid wrong answer on test case like that(-3 -2 -3)
        return (sum==mn?mx:max(sum-mn,mx));
    }
};