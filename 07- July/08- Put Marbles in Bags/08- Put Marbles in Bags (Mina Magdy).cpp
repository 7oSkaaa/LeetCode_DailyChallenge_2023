// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the difference between the maximum and minimum sum of pairs
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size(); // Get the size of the weights vector
        vector<int> nums; // Create an empty vector to store the sum of adjacent weights
        long long init = weights.front() + weights.back(); // Calculate the initial sum of the first and last weights
        for (int i = 1; i < n; i++) { // Iterate from the second weight to the last weight
            nums.emplace_back(weights[i - 1] + weights[i]); // Calculate the sum of the current weight and the previous weight and add it to the nums vector
        }
        sort(nums.begin(), nums.end()); // Sort the nums vector in ascending order
        long long mx = init; // Initialize the maximum sum with the initial sum
        long long mn = init; // Initialize the minimum sum with the initial sum
        for (int i = 0, j = nums.size() - 1; i < k - 1; i++, j--) { // Iterate k-1 times
            mn += nums[i]; // Add the smallest sums to the minimum sum
            mx += nums[j]; // Add the largest sums to the maximum sum
        }
        return mx - mn; // Return the difference between the maximum and minimum sums
    }
};
