// author : Omar Sanad
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // make two set to keep track the elements in nums1 and nums2
        set < int > st1, st2;

        // put all elements of nums1 in the st1
        for (auto &I : nums1)   st1.emplace(I);

        // put all elements of nums2 in the st2
        for (auto &I : nums2)   st2.emplace(I);

        // declaret the 2D vector which we will return
        vector < vector < int > > ret(2);

        // iterate over all elements in st1
        for (auto &I : st1)
            // if the element is not found in st2
            if (st2.find(I) == st2.end())
                // then add it to ret[0]
                ret[0].emplace_back(I);
        

        // Same as the prev step
        for (auto &I : st2)
            if (st1.find(I) == st1.end())
                ret[1].emplace_back(I);

        // return the answer
        return ret;
    }
};
