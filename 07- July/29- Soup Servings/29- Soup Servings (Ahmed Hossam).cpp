// Author: Ahmed Hossam

class Solution {
public:
    // Constants for array sizes and the limit for N
    static constexpr int Sz = 200, Limit = 4800;
    
    // 2D array to store memoized values
    double memo[Sz][Sz];

    // Function to calculate the probability of providing soup servings
    double soupServings(int N) {
        // Initialize memo array with -1
        memset(memo, -1, sizeof(memo));
        
        // If N is greater than the Limit, return 1.0
        // As the probability becomes almost 1 as N increases
        return N > Limit ? 1.0 : f((N + 24) / 25, (N + 24) / 25);
    }

    double f(int a, int b) {
        // Base case: if both a and b are non-positive, return 0.5
        // As half of the probability is reached when both servings are empty
        if (a <= 0 && b <= 0) return 0.5;

        // Base case: if either a or b is non-positive, return 1 or 0 respectively
        // If one serving is empty, probability of reaching this state is 1 (empty)
        // If the other serving is empty, probability of reaching this state is 0 (impossible)
        if (a <= 0 || b <= 0) return (a <= 0);

        // Check if the result for the current state (a, b) is already memoized
        double& ret = memo[a][b];
        if (ret == ret) return ret;

        // Calculate the probability for the current state using the given recursive formula
        // Probability at the current state = 0.25 * (sum of probabilities of 4 possible transitions)
        ret = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));

        // Return the calculated probability
        return ret;
    }
};
