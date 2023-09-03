// Author: Mina Magdy

class Solution {
public:
    // Function to calculate the binomial coefficient (n choose r)
    int nCr(int n, int r) {
        long long ans = 1;
        
        // To optimize, calculate from the smaller side
        if (r > n - r)
            r = n - r;
        
        // Calculate n! / (r! * (n - r)!)
        for (int i = 0; i < r; i++) {
            ans *= n - i;
            ans /= i + 1;
        }
        
        return ans;
    }
    
    // Function to find the number of unique paths from (0,0) to (m-1, n-1) in an m x n grid
    int uniquePaths(int m, int n) {
        // Use the combinatorial formula to find the number of paths
        return nCr(n + m - 2, n - 1);
    }
};
