// Author: Ahmed Hossam

class Solution {
public:
    // Declaration of variables
    int n;
    static constexpr int D = 500;
    vector < int > nums;
    vector < vector < int > > dp, adj;

    int LAS(int idx, int diff) {
        // Base case: if we reach the end of the array, return 0
        if (idx == n) return 0;
        
        // Memoization: check if the result for the current index and difference is already calculated
        int& ret = dp[idx][diff + D];
        if (~ret) return ret;
        
        // Initialize the result to 0
        ret = 0;
        
        // Find the index of the next element that forms an arithmetic subsequence
        int nxtIDX = adj[idx][diff + D];
        
        // If a valid next index exists, recursively calculate the length of the next arithmetic subsequence
        if (~nxtIDX)
            ret = 1 + LAS(nxtIDX, diff);
        
        return ret;
    }

    void build() {
        // Initialize the adjacency matrix with -1
        this -> adj = vector < vector < int > >(n, vector < int > (2 * D + 5, -1));
        
        // Iterate through the array and populate the adjacency matrix
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!~adj[i][nums[j] - nums[i] + D])
                    adj[i][nums[j] - nums[i] + D] = j;
    }

    int longestArithSeqLength(vector<int>& nums) {
        // Initialize the class variables
        this -> n = nums.size();
        this -> nums = nums;
        this -> dp = vector < vector < int > > (n, vector < int > (2 * D + 5, -1));
        
        // Build the adjacency matrix
        build();
        
        // Initialize the maximum length of the arithmetic subsequence to 1
        int maxLAS = 1;
        
        // Iterate through all possible differences and indices
        for (int diff = -D; diff <= D; diff++)
            for (int idx = 0; idx < n; idx++)
                // Update the maximum length if a longer arithmetic subsequence is found
                maxLAS = max(maxLAS, 1 + LAS(idx, diff));
        
        // Return the maximum length of the arithmetic subsequence
        return maxLAS;
    }
};
