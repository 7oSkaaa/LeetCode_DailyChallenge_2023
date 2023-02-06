// author: Esraa Syam
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // create a vector to store the answer
        vector < int > ans;
        // use two pointers to traverse the array
        // one pointer to traverse the first half of the array
        // the other pointer to traverse the second half of the array
        int l = 0 , r = n;
        // traverse the array until the second pointer reaches the end of the array
        while(r < nums.size()){
            ans.push_back(nums[l++]);
            ans.push_back(nums[r++]);
        }
        // return the answer
        return ans;
    }
};