// Author: Noura Algohary

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> differences(2);

        for(int num : nums1)
        {
            // num exists in nums1 and not in nums2
            // num is not present in the list 
            if(count(nums2.begin(), nums2.end(), num)==0 && count(differences[0].begin(), differences[0].end(), num) == 0)
                differences[0].push_back(num);
        }

        for(int num : nums2)
        {
            // num exists in nums2 and not in nums1
            // num is not present in the list 
            if(count(nums1.begin(), nums1.end(), num)==0 && count(differences[1].begin(), differences[1].end(), num) == 0)
                differences[1].push_back(num);
        }

        return differences;
    }
};