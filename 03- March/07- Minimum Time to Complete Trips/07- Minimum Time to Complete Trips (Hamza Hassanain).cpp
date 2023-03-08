// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    Approach
        Run a Binary Search useing 1 and (1^14) as our Boundires(Left and Right)
        Check if the selected value is valid ( we will see how to do that in just a second)
        If it is valid then search for a smaller that can also satisfy the condition
        If it is invalid then search for a bigger one

*/
class Solution
{
public:
    bool valid(vector<int> &time, long long cur, long long tot)
    {
        long long met = 0;
        for (int i = 0; i < time.size(); i++)
        {
            met += cur / time[i];
        }
        return met >= tot;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        const long long inf = 1e14;
        long long low = 1;
        long long high = inf;
        long long res = 0;
        while (low <= high)
        {
            long long cur = low + (high - low) / 2;
            if (valid(time, cur, totalTrips))
                res = cur, high = cur - 1;
            else
                low = cur + 1;
        }
        return res;
    }
};
