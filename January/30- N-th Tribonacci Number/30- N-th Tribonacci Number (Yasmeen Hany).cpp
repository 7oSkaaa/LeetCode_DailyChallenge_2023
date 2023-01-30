//Author: Eileanora

class Solution {
public:

    vector <int> dp;
    int calc(int n)
    {
        // base case
        if (n == 0 || n == 1)
            return n;
        if(n == 2)
            return 1;

        // memoization
        int& ret = dp[n];
        if(~ret)
            return ret;  // if calculated before return it
        
        // recursive case
        return ret = calc(n - 1) + calc(n - 2) + calc(n - 3);
    }
        
    int tribonacci(int n) {
        dp = vector <int> (n + 5 , -1);
        return calc(n);
    }
};