// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // we need the elements that are in of the arrays but not in the other
        // we can use set to get the unique elements
        // then we loop over the first set take the elements that are not in the second set
        // then we loop over the second set take the elements that are not in the first set

        // s1: set of nums1, s2: set of nums2
        set<int> s1, s2;
        // insert all elements of nums1 in s1
        for(auto&i: nums1) s1.emplace(i);
        // insert all elements of nums2 in s2
        for(auto&i: nums2) s2.emplace(i);

        // ans: vector of vectors to store the answer
        vector<vector<int>> ans(2);

        // loop over s1
        for(auto&i: s1)
            // if i is not in s2 then add it to ans[0]
            if(!s2.count(i)) ans[0].emplace_back(i);
        
        // loop over s2
        for(auto&i: s2)
            // if i is not in s1 then add it to ans[1]
            if(!s1.count(i)) ans[1].emplace_back(i);

        // return the answer
        return ans;
    }
};
