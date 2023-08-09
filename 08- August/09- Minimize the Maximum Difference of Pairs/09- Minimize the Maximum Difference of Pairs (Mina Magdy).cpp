// Author: Mina Magdy

class Solution {
public:
    // Function to minimize the maximum difference between elements in 'nums' by removing 'p' elements
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        
        // Sort the input array 'nums'
        sort(nums.begin(), nums.end());
        
        // Lambda function 'good' to check if it's possible to have 'p' or more non-overlapping intervals
        // with a maximum difference less than or equal to 'mx_diff'
        auto good = [&](int mx_diff) {
            int cnt = 0; // Counter for intervals
            int i = 1;   // Start with the second element
            while (i < n) {
                if (nums[i] - nums[i - 1] <= mx_diff)
                    cnt++, i++;
                i++;
            }
            return cnt >= p; // Return true if 'p' or more intervals are possible
        };
        
        int l = 0, r = 1; // Initialize left and right pointers for binary search
        
        // Find an upper bound for the maximum difference by doubling 'r' until 'good(r)' becomes true
        while (!good(r))
            r *= 2;
        
        int best = r; // Initialize the best result
        
        // Binary search to find the smallest 'mx_diff' that satisfies the 'good' condition
        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate the mid-point
            // Update 'best' and adjust search range based on whether 'good(mid)' is true or false
            (good(mid) ? best = mid, r = mid - 1 : l = mid + 1);
        }
        
        return best; // Return the minimized maximum difference
    }
};
