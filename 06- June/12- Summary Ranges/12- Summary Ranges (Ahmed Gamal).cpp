// Author: Ahmed Gamal

// for this problem, we will use two pointers, one for the start of the range and the other for the end of the range
// for each new range, we will move the second pointer until we reach the end of the range, then we will add the range to the answer

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // ans: the answer
        // a: the arrow string
        vector<string> ans;
        string a = "->";

        // i: the start of the range (inclusive)
        // j: the end of the range (exclusive)

        // every iteration, we will start the second pointer from the first pointer + 1
        // after each iteration, we will move the first pointer to the second pointer
        for(int i = 0, j = 1; i < nums.size(); i = j, j = i + 1) {
            // move the second pointer until we reach the end of the range
            while(j < nums.size() and nums[j] == nums[j - 1] + 1) {
                j++;
            }
            // add the range to the answer (if the range is one element, we will not add the arrow)
            auto curr = to_string(nums[i]) + (j == i + 1 ? "" : a + to_string(nums[j - 1]));
            ans.emplace_back(curr);
        }

        return ans;
    }
};