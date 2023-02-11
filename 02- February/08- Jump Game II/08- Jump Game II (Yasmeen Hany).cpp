// Author: Eileanora
class Solution {
public:
    #define inf 2000000000
    vector <int> dp;
    int min_jumps(vector<int>& nums , int& target , int i)
    {
        // base case
            // if we reached target then this is a valid answer , return 0 , if not it's not valid then exclude this path 
        if(i >= target)
            return(i == target? 0 : inf); 
    
        // memoization 
        int& ret = dp[i];
        if(~ret)
            return ret;
        
        // now we try every possible step from our index to nums[i] and with every step return the min steps done to reach the answer
        ret = inf;
        for(int j = 0; j <= nums[i]; j++) 
            ret = min(ret , 1 + min_jumps(nums , target , i + j));
        return ret;
    }

    int jump(vector<int>& nums) {
        int sz = int(nums.size()); 
        int target = sz - 1;
        dp = vector <int> (target + 10 , -1);
        int ans = min_jumps(nums , target , 0);
        return ans;
    }
    
};