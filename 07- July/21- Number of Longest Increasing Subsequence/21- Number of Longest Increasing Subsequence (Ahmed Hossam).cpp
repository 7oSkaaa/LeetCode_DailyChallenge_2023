// Author: Ahmed Hossam

class Solution {
public:

    // Define a template alias for pairs of integers.
    template < typename T = int > using Pair = pair < T, T >;
 
    // Function to merge two pairs according to the longest increasing subsequence (LIS) rules
    // If the first elements are equal, add the second elements; otherwise, take the pair with the larger first element.
    Pair < int > merge(const Pair < int >& a, const Pair < int >& b) {
        if (a.first == b.first)
            return {a.first, a.second + b.second};
        return max(a, b);
    }

    // Function to find the number of longest increasing subsequences in the given vector of integers.
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp array to store pairs representing the LIS ending at each index and their corresponding count.
        vector < Pair < int > > dp(n + 5, {1, 1});

        // Pair to keep track of the maximum LIS and its count found so far.
        Pair < int > maxLIS = {0, 0};

        // Iterating through the input vector to calculate the LIS for each element.
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                // If the current element is greater than the element at index j,
                // we can potentially extend the LIS.
                if (nums[i] > nums[j])
                    dp[i] = merge(dp[i], {dp[j].first + 1, dp[j].second});

        // Finding the overall maximum LIS and its count from the dp array.
        for (int i = 0; i < n; i++)
            maxLIS = merge(maxLIS, dp[i]);

        // Returning the count of the longest increasing subsequences.
        return maxLIS.second;
    }
};
