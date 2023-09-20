// Author: Ahmed Hossam

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Result vector to store the k smallest pairs
        vector < vector < int > > res;
        
        // If any of the input vectors is empty or k is zero, return an empty result
        if (nums1.empty() || nums2.empty() || k == 0)
            return res;
        
        // Custom comparator function to determine the order in priority queue based on sum of pair values
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        // Priority queue to store pairs, with the smallest sum at the top
        priority_queue < pair < int, int >, vector < pair < int, int > >, decltype(cmp) > pq(cmp);
        
        for (int i = 0; i < min(k, static_cast<int>(nums1.size())); ++i) {
            pq.push({i, 0}); // Push the indices of the pairs with the smallest values of nums1 into the priority queue
        }
        
        while (k-- > 0 && !pq.empty()) {
            // Get the pair with the smallest sum from the priority queue
            auto idx = pq.top();

            // Remove the pair from the priority queue
            pq.pop();

            // Add the pair to the result vector
            res.push_back({nums1[idx.first], nums2[idx.second]});
            
            // Push the next pair with the same index from nums1 but the next index from nums2
            if (idx.second + 1 < nums2.size()) 
                pq.push({idx.first, idx.second + 1});
        }
        
        // Return the k smallest pairs
        return res;
    }
};
