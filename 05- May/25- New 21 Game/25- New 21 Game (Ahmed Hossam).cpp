// Author: Ahmed Hossam

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        // Create a vector to store the probabilities.
        vector < double > dp(n + 1);

        // Initialize the current sum and the answer variables.
        double currSum = 1.0, ans = 0.0;

        // Set the initial probability for getting 0 points to 1.0.
        dp[0] = 1.0;

        // Calculate the probabilities for getting different points.
        for (int i = 1; i <= n; i++) {
            // Calculate the probability of getting i points.
            dp[i] = currSum / maxPts;

            // Update the current sum or the answer based on the value of i.
            // If i is less than k, update the current sum.
            // Otherwise, update the answer.
            (i < k ? currSum : ans) += dp[i];

            // If i - maxPts is greater than or equal to 0,
            // subtract the probability of getting (i - maxPts) points from the current sum.
            if (i - maxPts >= 0) 
                currSum -= dp[i - maxPts];
        }

        // Return the final answer.
        return ans;
    }
};
