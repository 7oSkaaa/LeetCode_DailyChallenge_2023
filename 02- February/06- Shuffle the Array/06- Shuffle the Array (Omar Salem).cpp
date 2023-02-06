//Author : Omar Salem
class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    //intialize varibale
    vector<int>ans;
    for (int i = 0; i <n ; ++i) {
        // push back x1 ,x2 .... ,xn
        ans.push_back(nums[i]);
        //push back y1 , y2 ,..... yn 
        ans.push_back(nums[i+n]);
    }
    // return answer ;
    return ans;
  }
};



