// Author: Ahmed Hossam

class Solution {
public:
    // A function to find the maximum number of uncrossed lines between two vectors
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {

        // Get the size of the two vectors
        int n = a.size(), m = b.size();

        // Create a 2D vector with 2 rows and m+1 columns
        // to store the maximum number of uncrossed lines
        vector < vector < int > > dp(2, vector < int > (m + 1));

        // Loop through the elements in the vectors, starting from the end
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                // Get the reference to the current element in the 2D vector
                int& ret = (dp[i & 1][j] = 0);

                // Calculate the maximum number of uncrossed lines
                ret = max(dp[(i + 1) & 1][j], dp[i & 1][j + 1]);

                // If the current elements in the vectors are the same, add 1 to the maximum number of uncrossed lines
                if(a[i] == b[j])
                    ret = max(ret, dp[(i + 1) & 1][j + 1] + 1);
            }
        }

        // Return the maximum number of uncrossed lines
        return dp[0][0];
    }
};
