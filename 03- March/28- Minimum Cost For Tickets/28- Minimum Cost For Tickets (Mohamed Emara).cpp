// Author : Mohamed Emara
// leetcode account : https://leetcode.com/MohamedEmara

class Solution {
public:
    int a, b, c;
    int n;
    int  arr[370];      // global copy of days vector
    int dp[370];        // to memoize soluions


    int rec(int idx)
    {
        if(idx >= n)        // base case
            return 0;
        
        int &ret = dp[idx];     // memoization
        if(~ret)
            return ret;

        // the first choice is to take the 1-day pass that lets you travel just this day
        int ch1 = rec(idx+1) + a;
   
        // if I took the 7-day pass then I can travel this day & next 6 days
        int limit_2 = arr[idx] + 6;
        // then, find the index is strictly greater than limit_2 (i > idx+6)
        int i = idx;
        while(arr[i] <= limit_2 && i < n)     // // i<n not to exceed the limit of the days
            i++;

        // the third choic is to buy 30-day pass so I can travel the next 29 days    
        int ch2 = rec(i) + b;
        int limit_3 = arr[idx] + 29;
        i = idx;
        while(arr[i] <= limit_3 && i < n)       // i<n not to exceed the limit of the days
            i++;
        int ch3 = rec(i) + c;

        // minimize between all three choices at every index
        return ret = min({ch1, ch2, ch3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        a = costs[0];
        b = costs[1];
        c = costs[2];

        n = days.size();
        for(int i=0; i<n; i++)
            arr[i] = days[i];

        memset(dp, -1, sizeof(dp));
        
        return rec(0);
    }
};
