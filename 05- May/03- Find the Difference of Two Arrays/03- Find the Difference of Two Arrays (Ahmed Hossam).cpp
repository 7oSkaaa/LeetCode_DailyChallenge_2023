// Author: Ahmed Hossam

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create two unordered sets of integers to store the unique values of nums1 and nums2, respectively.
        unordered_set<int> nums1_set, nums2_set;
        
        // Insert each element of nums1 into nums1_set.
        for(auto& x : nums1)
            nums1_set.insert(x);
        
        // Insert each element of nums2 into nums2_set.
        for(auto& x : nums2)
            nums2_set.insert(x);
        
        // Create a 2D vector of integers to store the differences between nums1 and nums2.
        vector<vector<int>> ans(2);
        
        // Iterate through each element in nums1.
        for(auto& x : nums1) {
            // If the element is not in nums2_set, add it to the first row of ans and insert it into nums2_set.
            if(!nums2_set.count(x)) {
                ans[0].push_back(x);
                nums2_set.insert(x);
            }
        }
        
        // Iterate through each element in nums2.
        for(auto& x : nums2) {
            // If the element is not in nums1_set, add it to the second row of ans and insert it into nums1_set.
            if(!nums1_set.count(x)) {
                ans[1].push_back(x);
                nums1_set.insert(x);
            }
        }
        
        // Return the resulting 2D vector.
        return ans;
    }

};
