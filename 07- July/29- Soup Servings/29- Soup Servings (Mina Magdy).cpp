// Author: Mina Magdy

class Solution {
public: 
    double dp[193][193]; // 2D array to store calculated probabilities
    
    Solution() {
        // Constructor: Initialize the dp array with -1 indicating that the probabilities have not been calculated yet
        memset(dp, -1, sizeof(dp));
    }
    
    // Recursive function to calculate the probability of soup servings for person A and person B
    double rec(int a, int b) {
        // Base case: If one of the persons has no soup remaining, return the appropriate probability
        if (!a || !b) {
            if (a == 0 && b == 0) return 0.5;
            if (a == 0) return 1;
            return 0;
        }
        
        double &ret = dp[a][b]; // Reference to the calculated probability to avoid redundant calculations
        
        // If the probability for these values of a and b has already been calculated, return it
        if (ret == ret)
            return ret;
        
        ret = 0; // Initialize the probability for the current a and b
        
        // Recursively calculate the probability for each possible distribution of soup
        for (int i = 0; i < 4; i++) {
            ret += 0.25 * rec(max(0, a - (4 - i)), max(0, b - i));
        }
        
        return ret; // Return the calculated probability
    }
    
    // Function to calculate the probability of soup servings for n servings
    double soupServings(int n) {
        int m = (n + 25 - 1) / 25; // Calculate the number of 25ml servings (rounded up) required for n servings
        if (m >= 193)
            return 1; // If the number of servings exceeds 192 (maximum supported value), return 1 as the probability
        return rec(m, m); // Otherwise, calculate the probability for m servings for both persons A and B
    }
};
