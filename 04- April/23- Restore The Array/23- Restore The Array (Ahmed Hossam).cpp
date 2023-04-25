// Author: Ahmed Hossam

class Solution {
public:

    // Set a constant value for modulo operation
    static constexpr int MOD = 1e9 + 7;

    // Declare a vector named dp to store the calculated values
    vector < long long > dp;

    // Define a function named add, which adds two integers and apply modulo operation on the result
    void add(long long& a, int b){
        a += b;
        if(a >= MOD)
            a -= MOD;
    }

    // Define a recursive function named cnt_ways which takes three arguments, 
    // idx denotes the current index of string s, k is an integer value,
    // and s is the string given as an input to the function.
    int cnt_ways(int idx, int k, const string& s){
        // If the end of the string is reached, then return 1
        if(idx == s.size()) return 1;
        
        // Use reference variable ret to store the value of dp[idx]
        // num is used to store the integer value of the substring s[idx...i]
        long long &ret = dp[idx], num = 0;
        
        // If the value of dp[idx] has been calculated before, return the stored value
        if(~ret) return ret;
        
        // Set ret to 0
        ret = 0;
        
        // Iterate from idx to the end of the string, and calculate the integer value of the substring s[idx...i] using variable num
        // If the integer value of the substring is less than or equal to k, then add the number of ways of splitting the string from index i+1 to the end of the string, to the value of ret
        for(int i = idx; i < s.size(); i++){
            num = num * 10 + (s[i] - '0');
            if(num >= 1 && num <= k)
                add(ret, cnt_ways(i + 1, k, s));
            else
                break;
        }
        return ret;
    }

    // Define a function named numberOfArrays which takes two arguments, 
    // s is a string and k is an integer value.
    int numberOfArrays(const string& s, int k) {
        // Initialize dp vector with -1 and size s.size() + 5
        dp = vector < long long > (s.size() + 5, -1);
        
        // Return the number of ways to split the string
        return cnt_ways(0, k, s);
    }

};
