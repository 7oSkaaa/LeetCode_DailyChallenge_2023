// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int dp[10001];
    bool valid(int n,int cur){
        return (n>cur?true:false);
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,0);
    }
    int rec(vector<int>& nums,int cur){
        // if reach last index just stop
        if(cur==nums.size()-1){
            return 0;
        }
        // if you visited this index before just return the asnwer donot jump again
        if(dp[cur]!=-1){
            return dp[cur];
        }
        int ch=100000;
        // try all possible jumps 
        for(int i=1;i<=nums[cur];i++){
            if(valid(nums.size(),cur+i)){
                ch=min(ch,rec(nums,cur+i)+1);
            }
        }
        // return minimum jumps
        return dp[cur]=ch;
    }
};