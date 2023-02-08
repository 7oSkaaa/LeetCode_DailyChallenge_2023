//Author: Walaa AbdElhady
class Solution {
public:
    int jump(vector<int>& nums) {
        //two pointers to move
        int l = 0, r = 0, numOfJump = 0;
        while (r < nums.size() - 1) {
            int maxJump = 0;// to store max jump of ele
            for (int i = l; i <= r; i++) {
                // Update the farthest reachable index of this jump
                maxJump = max(maxJump, i + nums[i]);
            }
            l = r + 1;//store the start idx of the next jump
            r = maxJump;//store  the farthest  idx of the next jump
            numOfJump++;// increase numOfJump by one
        }
        //min numOfJump
        return numOfJump;
    }
};