// auther: Esraa Syam
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // take o(nlogn) time 
        return nums;
    }
};