// Author: Ahmed Hossam

class Solution {
public:

    // Define long long as ll
    typedef long long ll;

    // Define a function named mostPoints that takes a 2D vector of integers as input and returns a long long.
    ll mostPoints(vector<vector<int>>& v) {

        // Get the number of rows in the vector.
        int n = v.size();

        // Initialize a vector of long longs of size n + 1.
        vector < ll > dp(n + 1);

        // Iterate over the vector in reverse order.
        for(int i = n - 1; i >= 0; i--){

            // Get the first and second elements of the i-th row in the vector.
            auto [points, brainpower] = make_pair(v[i][0], v[i][1]);

            // the first option is to skip this question
            // the second option is to use this question and skip the next brainpower questions
            dp[i] = max(dp[i + 1], points + dp[min(i + brainpower + 1, n)]);
        }

        // Return the first element of the dp vector.
        return dp[0];
    }
};
