// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>path;
        rec(path,0,nums);
        return ans;
    }
    void rec(vector<int>& path ,int cur ,vector<int>& nums){
        // check if current subarray have more than one element
        if(path.size()>1){
            ans.push_back(path);
        }
        map<int,bool>vis;
        for(int i=cur;i<nums.size();i++){
            //check if current element has added to path ( to avoid duplicates pathes)
            if((path.empty() || path.back()<=nums[i] ) && !vis[nums[i]]){
                path.push_back(nums[i]);
                rec(path,i+1,nums);
                path.pop_back();
                vis[nums[i]]=true;
            }
        }
    }
};