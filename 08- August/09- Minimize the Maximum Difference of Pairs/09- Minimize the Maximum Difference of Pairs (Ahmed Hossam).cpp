// Author: Ahmed Hossam

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());
        
        // Define a lambda function (is_good) that takes an integer (m) and returns a boolean
        auto is_good = [&](int m){
            int cnt_pairs = 0; // Initialize a counter for pairs
            
            // Iterate through the input vector
            for(int i = 0; i < n - 1; i++){
                // Check if the difference between the current element and the next element is less than or equal to m
                if(nums[i + 1] - nums[i] <= m)
                    cnt_pairs++, i++; // Increment the counter and the index to skip the next element
            }
            
            // Return true if the count of pairs is greater than or equal to p, otherwise return false
            return cnt_pairs >= p;
        };
        
        // Initialize variables l, r, and ans
        int l = 0, r = 1e9, ans = -1;
        
        // Perform a binary search to find the minimum value of m that satisfies the is_good condition
        while(l <= r){
            int m = l + (r - l) / 2;
            // Update l and r based on the is_good condition
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        
        // Return the final answer
        return ans;
    }
};
