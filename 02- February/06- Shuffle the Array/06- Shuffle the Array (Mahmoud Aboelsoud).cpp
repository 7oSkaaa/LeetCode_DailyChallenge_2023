// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // initialize the answer vector with size 2*n
        vector<int> ans(2 * n);
        // loop over the array with two pointers i and j, i on the first half of the array and j on the second half
        // and another pointer k to fill the answer vector with the values of the first half and the second half  
        for(int i = 0, j = n, k = 0; i < n ; i++, j++, k += 2)
            ans[k] = nums[i], ans[k + 1] = nums[j];

        return ans;
    }
};
