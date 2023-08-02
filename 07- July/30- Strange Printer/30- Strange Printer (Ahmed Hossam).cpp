// Author: Ahmed Hossam

class Solution {
public:
    // Recursive function to calculate the minimum number of turns required to print a substring
    // The function takes left index (l), right index (r), the input string (s), and a memoization 2D vector (dp)
    int min_turns(int l, int r, string &s, vector < vector < int > > &dp) {
        // If the substring contains only one character, it requires only one turn to print
        if (l == r) return 1;
        
        // Use a reference to ret to store and access the result of the current state in the memoization table
        int &ret = dp[l][r];
        
        // If the result is already calculated, return it
        if (~ret) return ret;
        
        // Initialize ret to the maximum integer value to find the minimum number of turns
        ret = INT_MAX;
        
        // Loop through all possible divisions of the substring and calculate the minimum turns required
        for (int i = l; i < r; i++)
            ret = min({ret, min_turns(l, i, s, dp) + min_turns(i + 1, r, s, dp)});
        
        // Return the minimum turns, subtracting 1 if the characters at the left and right indices are the same
        return ret -= (s[l] == s[r]);
    }
    
    int strangePrinter(string& s) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize a 2D memoization vector with -1 to store previously calculated results
        vector < vector < int > > dp(n, vector < int >(n, -1));
        
        // Call the recursive function to find the minimum turns for the whole input string
        return min_turns(0, n - 1, s, dp);
    }
};
