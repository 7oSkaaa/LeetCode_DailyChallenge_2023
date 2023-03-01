// author: Esraa Syam
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // take O(nlogn) time 
        return nums;
    }
};
