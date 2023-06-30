// Author: Ahmed Hossam

class Solution {
public:

    int n; // Number of rods
    static constexpr int MAXN = 5000, INF = 1e9; // Constants for array size and infinite value
    vector < int > rods; // Vector to store the lengths of the rods
    vector < vector < int > > dp; // Dynamic programming array

    // Function to calculate the maximum score
    int max_score(int idx, int diff) {
        // Base case: If all rods have been processed, return 0 if the difference is 0, or -INF otherwise
        if (idx == n) return (!diff ? 0 : -INF);
        
        // Reference to the maximum score at current index and difference
        int& ret = dp[idx][diff + MAXN];
        
        // If the maximum score has already been calculated, return it 
        if (~ret) return ret; 

        // Scenario 1: Exclude the current rod
        ret = max_score(idx + 1, diff); 
        
        // Scenario 2: Include the current rod as positive difference
        ret = max(ret, rods[idx] + max_score(idx + 1, diff + rods[idx]));
        
        // Scenario 3: Include the current rod as negative difference
        ret = max(ret, max_score(idx + 1, diff - rods[idx]));

        // Return the maximum score
        return ret;
    }

    int tallestBillboard(vector<int>& rods) {
        this -> rods = rods; // Assign the input rods to the member variable
        this -> n = rods.size(); // Set the number of rods

        // Initialize the dynamic programming array with -1
        this -> dp = vector < vector < int > > (n, vector < int > (2 * MAXN + 5, -1));
        
        // Return the maximum score starting from index 0 and with 0 difference
        return max_score(0, 0);
    }
};
