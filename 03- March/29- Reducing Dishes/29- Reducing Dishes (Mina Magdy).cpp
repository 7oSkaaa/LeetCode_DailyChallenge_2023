// Author: Mina Magdy

// Function to calculate the maximum satisfaction value.
class Solution {
public:
    // Initializing the answer variable with zero value.
    int maxSatisfaction(vector<int>& sat) {
        long long ans = 0;
        // Sorting the given array in non-increasing order.
        sort(sat.begin(), sat.end(), greater<>());
        // Initializing the sum variable with zero value.
        long long sum = 0;
        // Initializing the current variable with zero value.
        long long cur = 0;
        // Looping through each element of the sorted array.
        for (int i = 0; i < (int)sat.size(); i++) {
            // Adding the current element to the sum.
            sum += sat[i];
            // Adding the product of the sum and the current element to the current variable.
            cur = cur + sum;
            // Updating the answer variable with the maximum value between its current value and the current variable.
            ans = max(ans, cur);
        }
        // Returning the maximum satisfaction value.
        return ans;
    }
};
