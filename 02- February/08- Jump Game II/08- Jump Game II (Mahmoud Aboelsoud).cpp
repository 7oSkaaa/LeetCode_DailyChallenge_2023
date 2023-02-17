// Author: Mahmoud Aboelsoud

class Solution {
public:
    // the idea is to use dp to store the minimum number of jumps to reach the end from each index
    // then we can use it to calculate the minimum number of jumps to reach the end from the first index

    int n;
    vector<int> dp, nums;

    int min_jumps(int idx){
        // if the index is out of the range of the array, return 1e5
        if(idx >= n) return 1e5;
        // if we reached the end, return 0
        if(idx == n - 1) return 0;
        
        // if we already calculated the minimum number of jumps to reach the end from this index, return it
        if(dp[idx] != -1) return dp[idx];

        // try to reach the end from the next indices by jumping from the current index
        // and return the minimum number of jumps
        int ans = 1e5;
        for(int i = 1; i <= nums[idx]; i++)
            ans = min(ans, 1 + min_jumps(idx + i));

        // store the minimum number of jumps to reach the end from this index
        // and return it
        return dp[idx] = ans;
    }


    int jump(vector<int>& nums) {
        this -> nums = nums;
        n = nums.size();
        // initialize dp with -1
        dp.assign(n, -1);

        // return the minimum number of jumps to reach the end from the first index
        return min_jumps(0);
    }
};
