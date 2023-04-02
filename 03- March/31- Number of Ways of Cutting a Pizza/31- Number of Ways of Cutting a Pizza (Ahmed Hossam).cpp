// Author: Ahmed Hossam

class Solution {

    // define long long 
    #define ll long long 

    // constant number for MOD
    static constexpr int MOD = 1e9 + 7;

    // Define a private function to add two long integers
    void add(ll &a, ll &b) { 
        a += b;
        if(a >= MOD)
            a -= MOD;
    }

public:
    // Define a public function to count the number of ways to split the matrix
    int ways(vector<string>& A, int K) {
        // Get the matrix size
        int M = A.size(), N = A[0].size();

        // Define a 2D vector cnt to count the number of 'A's in the submatrix from (i, j) to (M, N)
        vector < vector < int > > cnt(M + 1, vector < int >(N + 1));

        // Calculate cnt using a nested loop
        for (int i = M - 1; i >= 0; --i) {
            int s = 0;
            for (int j = N - 1; j >= 0; --j) {
                s += A[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }

        // Define a 3D vector dp to store the number of ways to split the submatrix from (i, j) to (M, N) into K submatrices
        vector < vector < vector < ll > > > dp(M + 1, vector < vector < ll > >(N + 1, vector < ll > (K + 1)));
       
        // Calculate dp using nested loops
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                // Initialize the base case
                dp[i][j][1] = cnt[i][j] > 0;
                
                // Calculate dp using nested loops
                for (int k = 2; k <= K; ++k) {
                    for (int t = i + 1; t < M; ++t) {
                        // Skip invalid splits
                        if (cnt[i][j] == cnt[t][j]) continue;
                        if (cnt[t][j] == 0) break;
                        // Update dp
                        add(dp[i][j][k], dp[t][j][k - 1]);
                    }

                    for (int t = j + 1; t < N; ++t) {
                        // Skip invalid splits
                        if (cnt[i][j] == cnt[i][t]) continue;
                        if (cnt[i][t] == 0) break;
                        // Update dp
                        add(dp[i][j][k], dp[i][t][k - 1]);
                    }
                }
            }
        }

        // Return the number of ways to split the whole matrix into K submatrices
        return dp[0][0][K];
    }
};
