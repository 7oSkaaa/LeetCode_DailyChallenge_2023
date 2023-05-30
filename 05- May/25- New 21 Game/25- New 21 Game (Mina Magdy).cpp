// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the winning probability in the New 21 Game
    double new21Game(int n, int k, int maxPts, int curr = 0) {
        // Base case: If k is 0, the game is already over, and the probability of winning is 1.
        if (k == 0) return 1;

        double dp[n + 1]; // Array to store the probabilities
        memset(dp, -1, sizeof(dp)); // Initialize the array with -1

        double sum = 0; // Variable to store the sum of probabilities
        int r = 0; // Variable to store the right endpoint of the interval

        // Fill the probabilities for the rightmost interval [k, min(n, (k-1)+maxPts)]
        for (int i = k; i <= min(n, (k - 1) + maxPts); i++) {
            dp[i] = 1; // Set the winning probability to 1 for these values
            sum += dp[i]; // Update the sum
            r = i; // Update the right endpoint
        }

        // Calculate the probabilities for the remaining values in reverse order
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = sum / maxPts; // Calculate the average of the next maxPts values
            if (r - i + 1 > maxPts)
                sum -= dp[r--]; // If the window size exceeds maxPts, remove the leftmost probability
            sum += dp[i]; // Add the current probability to the sum
        }

        return dp[0]; // Return the winning probability for starting with 0 points
    }
};
