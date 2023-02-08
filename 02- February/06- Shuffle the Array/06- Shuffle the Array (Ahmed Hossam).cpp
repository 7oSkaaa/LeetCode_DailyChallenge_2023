// Author: Ahmed Hossam

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // the shuffled vector 
        vector < int > shuffled_vec;

        // we will devide the vector into two halves and add one element from first one and one element from second one
        for(int i = 0, j = n; i < n; i++, j++)
            shuffled_vec.push_back(nums[i]), shuffled_vec.push_back(nums[j]);

        // the resulted vector
        return shuffled_vec;
    }
};
