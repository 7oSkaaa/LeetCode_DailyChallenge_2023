// Author: Ahmed Hossam

class Solution {
public:

    // Define a unordered_map called dp to store previously calculated results
    unordered_map < string , bool > dp;

    // A recursive function to determine if s1 is a scramble of s2
    bool solve(const string& s1, const string& s2){
        // If s1 and s2 are equal, return true
        if(s1 == s2) return true;

        // If the size of s1 is less than or equal to 1, return false
        if( s1.size() <= 1) return false;
        
        // Create a key using s1 and s2 and check if it already exists in the unordered_map dp. 
        // If it exists, return the value
        string key = s1 + '#' + s2;
        if(dp.count(key)) return dp[key];

        // Get the size of s1
        int n = s1.size();
        
        for(int i = 1 ; i <= n - 1; i++){
            // Check if s1[0:i] is a scramble of s2[n-i:i] and s1[i:n] is a scramble of s2[0:n-i]
            if(solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return dp[key] = true;
            
            // Check if s1[0:i] is a scramble of s2[0:i] and s1[i:n] is a scramble of s2[i:n]
            if(solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return dp[key] = true;
        }

        // If none of the above conditions are true, set the value of key to false and return it
        return dp[key] = false;
    }

    // A function to determine if s1 is a scramble of s2
    bool isScramble(const string& s1, const string& s2) {
        // If the size of s1 is not equal to the size of s2, return false
        if(s1.size() != s2.size())
            return false;
        
        // Call the solve function and return its value
        return solve(s1, s2);
    }
};
