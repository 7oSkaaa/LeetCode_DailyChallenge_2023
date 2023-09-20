// Author: Mina Magdy

class Solution {
public:
    // Define a 3D DP array to store the calculated probabilities
    double dp[101][25][25];
    // Define a vector of pairs to represent the possible knight move directions
    vector<pair<int, int>> dir;

    // Constructor to initialize the DP array and direction vector
    Solution() {
        // Set all values in the DP array to -1 (indicating not calculated yet)
        memset(dp, -1, sizeof(dp));
        // Populate the direction vector with the possible knight moves
        dir = {{1, 2}, {2, 1}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}, {2, -1}, {-1, 2}};
    }

    // Function to check if a position (i, j) is valid in an n x n board
    bool valid(int i, int j, int n) {
        return 0 <= i && i < n && 0 <= j && j < n;
    }

    // Function to calculate the probability of a knight staying on the board after making k moves
    double knightProbability(int n, int k, int row, int column) {
        // If the position (row, column) is not valid, the probability is 0
        if (!valid(row, column, n))
            return 0;

        // If k is 0, the probability of staying on the board is 1 (base case)
        if (k == 0)
            return 1;

        // Use a reference variable 'ret' to store the result for current state
        double &ret = dp[k][row][column];

        // If the result has already been calculated, return it
        if (ret == ret)
            return ret;

        // Initialize 'ret' to 0
        ret = 0;

        // Iterate over all possible knight move directions
        for (auto& [dx, dy] : dir) {
            // Calculate the probability of moving to the next position
            ret += 1 / 8.0 * knightProbability(n, k - 1, row + dx, column + dy);
        }

        // Return the calculated probability for current state
        return ret;
    }
};
