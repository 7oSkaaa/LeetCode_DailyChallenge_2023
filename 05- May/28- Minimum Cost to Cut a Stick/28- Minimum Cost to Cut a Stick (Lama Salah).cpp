// Author: Lama Salah

class Solution {
    vector<int> cuts; // Positions where the stick can be cut.
    int memo[105][105]; // Memoization array to store computed results.

public:
    int dp(int l, int r) {    
        // Base case: If the left index is greater than the right index,
        // the segment is empty, so the cost is 0.
        if (l > r) return 0; 
        
        int& ans = memo[l][r]; // Reference to store the computed result for the current segment.
        
        // If the result is already computed, return it.
        if (~ans) return ans; 
        
        ans = INT_MAX; // Initialize 'ans' with the maximum possible value.

        // Try each possible position 'i' for cutting the stick and update the minimum cost.
        for (int i = l; i <= r; i++) {
            ans = min(ans, cuts[r + 1] - cuts[l - 1] + dp(l, i - 1) + dp(i + 1, r));        
        }
    
        // Store the minimum cost for the current segment in the memoization array.
        return ans; 
    }
  
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end()); // Sort the cut positions in ascending order.
        
        vector<int> c = {0}; // Initialize a new vector with 0 (start of the stick).
        
        // Add the cut positions to the vector.
        for (auto& i : cuts) c.emplace_back(i); 
        
        c.push_back(n); // Add 'n' (the size of the stick) to the vector.

        // Assign the 'c' vector to the member variable 'cuts' of the class.
        this->cuts = c; 
        
        // Initialize the memoization array with -1 to indicate that results are not computed yet.
        memset(memo, -1, sizeof memo); 

        // Return the minimum cost to cut a stick.
        return dp(1, c.size() - 2); 
    }
};
