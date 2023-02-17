//Author: Walaa AbdElhady
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;// store Array after shuffle
        for (int i = 0; i < n; i++) {//loop to the middel of array
            //every iteration we push current element 
            //and the element of the second part lacated in index n+i (the same position but in second part of array)
            ans.push_back(nums[i]);
            ans.push_back(nums[n + i]);
        }
        return ans;
    }
};