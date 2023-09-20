// Author: Ahmed Hossam

class Solution {
public:
    double myPow(double x, int n) {
        // Initialize a variable "power" to store the result of the power calculation, and set it to 1 initially
        double power = 1;
        // Check if the value of "n" is negative and store the result in a boolean variable "neg"
        bool neg = (n < 0);

        // Start a loop that continues as long as "n" is non-zero
        while (n) {
            // Check if "n" is odd (n % 2 is non-zero), and if so, multiply "power" with "x"
            if (n % 2)
                power *= x;
            
            // Square the value of "x" in each iteration
            x *= x;

            // Divide "n" by 2 in each iteration to perform binary exponentiation
            n /= 2;
        }

        // Return the final result, either "power" or its reciprocal based on the value of "neg"
        return (neg ? 1 / power : power);
    }
};
