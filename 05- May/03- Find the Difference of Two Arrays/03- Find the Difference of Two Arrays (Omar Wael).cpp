// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        // create visited array of 2 rows 
        // first row-> nums1
        // second row-> nums2
        int vis[2][2002]={0};
        // visit all num1 elements
        for(auto i:nums1){
            // i+1000 -> to avoid negative index
            vis[0][i+1000]=1;
        }
        // visit all num2 elements
        for(auto i:nums2){
            // i+1000 -> to avoid negative index
            vis[1][i+1000]=1;
        }
        vector<int>tmp;
        for(auto i:nums1){
            // check if current number is unvisited in nums2
            if(!vis[1][i+1000]){
                tmp.push_back(i);
                // visit it to avoid dublicates
                vis[1][i+1000]=1;
            }
        }
        ans.push_back(tmp);
        vector<int>tmp1;
        for(auto i:nums2){
            // check if current number is unvisited in nums1
            if(!vis[0][i+1000]){
                tmp1.push_back(i);
                // visit it to avoid dublicates
                vis[0][i+1000]=1;
            }
        }
        ans.push_back(tmp1);
        return ans;
    }
};
