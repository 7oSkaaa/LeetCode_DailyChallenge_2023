// Author: Mina Magdy

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); // Number of elements in nums1
        vector<int> idx(n); // Vector to store indices of nums1
        iota(idx.begin(), idx.end(), 0); // Initialize idx with indices from 0 to n-1
        sort(idx.begin(), idx.end(), [&](auto &a, auto &b) {
            return nums1[a] < nums1[b]; // Sort idx based on the values of nums1 in ascending order
        });
        vector<pair<int, int>> vec;
        for (int k = 0; k < n; k++) {
            vec.emplace_back(nums2[idx[k]], k); // Create a vector of pairs (nums2 value, corresponding idx[k])
        }
        sort(vec.begin(), vec.end()); // Sort vec in ascending order based on nums2 values
        int j = n - 1; // Pointer for iterating nums1 in reverse order
        int cnt = 0; // Counter for the number of elements chosen
        long long sum = 0, mx = 0; // sum: sum of chosen nums1 values, mx: maximum score
        set<int> removedIndices; // Set to keep track of removed indices
        for (int v = 0; v < n; v++) {
            auto &[vl, id] = vec[v]; // vl: nums2 value, id: corresponding idx[k]
            removedIndices.insert(idx[id]); // Add the corresponding idx to removedIndices set
            if (id > j) {
                cnt--; // Decrement the counter if id is greater than j
                sum -= nums1[idx[id]]; // Subtract the value at idx[id] from the sum
            }
            while (cnt < k - 1 && j >= 0) {
                if (removedIndices.count(idx[j])) { // Skip the index if it is already removed
                    j--;
                    continue;
                }
                cnt++; // Increment the counter
                sum += nums1[idx[j--]]; // Add the value at idx[j] to the sum and move the pointer j backwards
            }
            if (cnt == k - 1) {
                mx = max(mx, (sum + nums1[idx[id]]) * vl); // Calculate the score and update mx if it's greater
            }
        }
        return mx; // Return the maximum score
    }
};
