//Author: Sara Hamza
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector <int> ans(2*n);

        //ans vector's even indices elements = nums vector's first n elements respectively
        //ans vector's odd indices elements = nums vector's second n elements respectively

        for(int i = 0; i < n; ++i){
            //even indices
            ans[2*i] = nums[i];
            //odd indices
            ans[2*i+1] = nums[i+n];
        }
        return ans;
    }
};
