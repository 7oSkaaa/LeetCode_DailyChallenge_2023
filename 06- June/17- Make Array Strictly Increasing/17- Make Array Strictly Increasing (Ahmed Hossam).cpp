// Author: Ahmed Hossam

// Define constants
constexpr int N = 2005, INF = 2e9;

// Define variables and arrays
int dp[N][N][2];  // Dynamic programming array
int vis[N][N][2];  // Visited array
int n, m, id;  // Variables for size and identification
vector<int> a, b;  // Vectors for input arrays
bool is_memed = false;  // Flag for memory initialization

class Solution {
public:
    // Function to calculate the minimum moves
    int min_moves(int a_idx, int b_idx, bool is_a_last) {
        // Base case: if all elements in arr1 have been processed, return 0
        if (a_idx == n)
            return 0;
        
        // Reference to the current state in dp array
        int& ret = dp[a_idx][b_idx][is_a_last];
        
        // Check if the state has already been visited
        if (vis[a_idx][b_idx][is_a_last] == id)
            return ret;
        
        // Mark the state as visited
        vis[a_idx][b_idx][is_a_last] = id;
        
        // Initialize the minimum moves to a large value
        ret = INF;
        
        // Determine the last number in the sequence
        int last_num = is_a_last ? a[a_idx - 1] : b[b_idx - 1];
        
        // Case 1: Include the next element from arr1 if it is greater than the last number
        if (a[a_idx] > last_num)
            ret = min(ret, min_moves(a_idx + 1, b_idx, true));
        
        // Case 2: Include the next element from arr2 if it can make the sequence increasing
        int idx = upper_bound(b.begin(), b.end(), last_num) - b.begin();
        if (idx != m)
            ret = min(ret, 1 + min_moves(a_idx + 1, idx + 1, false));
        
        // Return the minimum moves
        return ret;
    }

    // Constructor
    Solution() {
        // Increment the identification
        id++;

        // Initialize the dp and visited arrays only once
        if (!is_memed) {
            memset(dp, -1, sizeof(dp));
            memset(vis, -1, sizeof(vis));
            is_memed = true;
        }
    }

    // Function to find the minimum moves to make the array increasing
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // Sort the second array in ascending order
        sort(arr2.begin(), arr2.end());
        
        // Assign the input arrays and their sizes
        a = arr1, b = arr2;
        n = a.size(), m = b.size();
        
        // Calculate the minimum moves starting with arr1[0] as the first element
        int best_moves = min(min_moves(1, 0, true), 1 + min_moves(1, 1, false));
        
        // If the minimum moves are greater than or equal to INF, set it to -1
        if (best_moves >= INF)
            best_moves = -1;
        
        // Return the best_moves
        return best_moves;
    }
};
