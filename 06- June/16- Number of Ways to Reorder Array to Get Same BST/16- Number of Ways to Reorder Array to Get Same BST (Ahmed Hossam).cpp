// Author: Ahmed Hossam

// Constants
constexpr int N = 1000, MOD = 1e9 + 7;
// 2D vector to store combinations
vector<vector<int>> nCr;
// if the nCr not build
bool is_nCr_built = false;

// Function to perform modular multiplication
template <typename T = int>T mul_mod(std::initializer_list<T> vals, T mod) {
    T res = 1;
    // Iterate through the values and multiply them, taking modulo at each step
    for (auto x : vals) res = (1LL * res * (x % mod)) % mod;
    return res;
}

// Function to build the nCr table
void build() {
    // Resize the nCr vector
    nCr = vector < vector < int > >(N + 5, vector < int > (N + 5));
    // Initialize the base cases
    for (int n = 0; n <= N; n++)
        nCr[n][0] = 1;
    // Calculate the combinations using dynamic programming
    for (int n = 1; n <= N; n++)
        for (int r = 1; r <= n; r++)
            nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % MOD;
}

class Solution {
public:

    // Constructor to build the nCr table
    Solution() {
        if(!is_nCr_built)
            build();
        is_nCr_built = true;
    }

    // Recursive function to compute the number of ways to split the array
    int dfs(const vector<int>& nums) {
        // Base case: If the array size is less than or equal to 1, return 1
        if (nums.size() <= 1)
            return 1;
        // Separate the array into two parts: Left and Right
        vector<int> Left, Right;
        for (int i = 1; i < nums.size(); i++)
            (nums[i] >= nums[0] ? Right : Left).emplace_back(nums[i]);
        int L = Left.size(), R = Right.size();
        // Compute the number of ways recursively using modular multiplication
        return mul_mod({dfs(Left), dfs(Right), nCr[L + R][L]}, MOD);
    }

    // Function to compute the number of ways to split the array
    int numOfWays(const vector<int>& nums) {
        // Compute the number of ways recursively and subtract 1, then take modulo
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
