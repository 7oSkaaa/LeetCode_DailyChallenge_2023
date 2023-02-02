// author: Esraa Syam
class Solution {
public:
    vector < int > dp;
    int solve(int n){ 
        // base case
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        // memoization
        // use dp[n] to store the answer of n so we don't need to calculate it again
        int & ret = dp[n]; // ret is a reference to dp[n] so if we change ret we change dp[n]
        if(~ret) return ret; // if ret != -1 then return ret because we already calculated it
        // recursive case
        // Tn+3 = Tn + Tn+1 + Tn+2 -------> we can minuse 3 from all so -> Tn = Tn-3 + Tn-2 + Tn-1
        return ret = solve(n - 3) + solve(n - 2) + solve(n - 1);
    }
    int tribonacci(int n) {
        // initialize dp with -1
        dp.assign(n + 1 , -1);
        return solve(n);
    }
};