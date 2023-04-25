// Author: Mina Magdy

// Define a long long integer variable named "ll"
#define ll long long
// Define a constant integer variable named "MOD" with a value of 1e9+7
#define MOD 1e9 + 7

// Define a class named "Solution"
class Solution {
public:
    // Define a 2D vector "dp" to store intermediate values for dynamic programming
    vector<vector<int>> dp;
    // Constructor of the "Solution" class
    Solution() {
        // Declare two integer constants named "N" and "M" and assign them values
        const int N = 1e5 + 5;
        const int M = 12;
        // Initialize the 2D vector "dp" with N rows and M columns with -1
        dp.assign(N, vector<int>(M, -1));
    }
    // A function named "numberOfArrays" with three parameters: a reference to a string, an integer, and two integer variables
    int numberOfArrays(string &s, int k, int idx = 0, int cnt = 0, ll sum = 0) {
        // Add the current digit to the "sum"
        sum = sum * 10 + s[idx] - '0';
        // Increment the "cnt" variable
        cnt++;
        // If the "sum" is greater than "k" or equal to zero, return 0
        if (sum > k || sum == 0) return 0;
        // If the index is equal to the size of the string minus one, return 1
        if (idx == s.size() - 1) return 1;
        // Declare an integer reference variable "ret" and assign it the value of the 2D vector "dp" at position (idx, cnt)
        int &ret = dp[idx][cnt];
        // If the "ret" value is not equal to -1, return "ret"
        if (~ret) return ret;
        // Recursively call the "numberOfArrays" function to compute the number of arrays without including the current digit
        ret = numberOfArrays(s, k, idx + 1, 0, 0);
        // Recursively call the "numberOfArrays" function to compute the number of arrays including the current digit
        ret += numberOfArrays(s, k, idx + 1, cnt, sum);
        // If "ret" is greater than or equal to "MOD", subtract "MOD" from "ret"
        if (ret >= MOD) ret -= MOD;
        // Return "ret"
        return ret;
    }
};
