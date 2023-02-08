// author: Esraa Syam
class Solution {
public:
    // dp vector to store the answer for each index
    vector < int > dp;
    int rec(int idx , vector < int > &v){
        // if we reach the end of the vector return 0
        // base case
        if(idx >= v.size() - 1) return 0;
        // reference to the answer for the current index
        // to avoid calculating the answer for the current index more than once
        // memoization
        int &ret = dp[idx];
        if(~ret) return ret;
        ret = 1e9;
        // try all the possible jumps from the current index
        // and return the minimum number of jumps
        // recusive case
        for(int i = 1; i <= v[idx]; i++){
            ret = min(ret , 1 + rec(idx + i , v));
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        // initialize the dp vector with -1
        dp.assign(nums.size() , -1);
        return rec(0 , nums);
       
    }
};