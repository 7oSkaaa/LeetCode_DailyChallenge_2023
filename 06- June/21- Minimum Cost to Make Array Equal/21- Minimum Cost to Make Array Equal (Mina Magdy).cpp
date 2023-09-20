// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the minimum cost
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size(); // Get the size of the input vectors
        long long sum_cost = 0; // Initialize the sum of costs
        long long factor = 0; // Initialize the factor

        // Calculate the sum of costs and the factor by iterating over the vectors
        for (int i = 0; i < n; i++) {
            sum_cost += cost[i];
            factor += 1ll * nums[i] * cost[i];
        }

        vector<pair<long long, long long>> pr_sort; // Vector to store pairs of nums and costs
        // Populate the pr_sort vector with pairs of nums and costs
        for (int i = 0; i < n; i++) {
            pr_sort.emplace_back(nums[i], cost[i]);
        }

        sort(pr_sort.begin(), pr_sort.end()); // Sort the pr_sort vector in ascending order of nums

        long long ans = 1e18; // Initialize the answer to a large value
        int idx = 0; // Initialize the index

        // Iterate over the pr_sort vector
        for (int i = 0; i < pr_sort.size(); i++) {
            factor -= 2 * pr_sort[i].first * pr_sort[i].second; // Update the factor
            sum_cost -= 2 * pr_sort[i].second; // Update the sum of costs
            ans = min(ans, factor - pr_sort[i].first * sum_cost); // Update the answer
        }

        return ans; // Return the minimum cost
    }
};
