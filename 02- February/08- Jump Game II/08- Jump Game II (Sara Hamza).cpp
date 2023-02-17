//Author: Sara Hamza

class Solution {
public:
    int memo[10009];
    int maxJump(int i, vector<int>& nums){

        //valid (base) case
        if(i == nums.size()-1) {
            return 0;
        }
        //invalid cases
        //note: 0 -> means i can't move forward anymore
        if(i >= nums.size() || nums[i]==0) {
            return 1e9+9;
        }
        // memorization
        int &ret = memo[i];

        //check if this is already calculated before
        if(~ret) return ret;

        //try all possible jumps that could be made from this(i-th) point
        //and take the min among them
        ret = 1e9+9;
        for(int j = i+1; j<=nums[i]+i; ++j){
            ret = min(ret, 1+maxJump(j, nums));
        }

        return ret;
    }
    int jump(vector<int>& nums) {
        /*
            approach: try all possible cases and take the min no of jumps among them
        */
        memset(memo, -1, sizeof memo);

        return maxJump(0, nums);

    }
};
