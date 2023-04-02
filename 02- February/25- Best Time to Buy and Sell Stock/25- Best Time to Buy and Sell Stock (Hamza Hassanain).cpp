// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &ps)
    {
        int res = 0;
        if (ps.size() == 1)
            return res;
        vector<int> mins(ps.size()), maxes(ps.size()); // make to arrays to store the min and max for current position
        // while the min must come before max we start by getting min from front, and max form the back

        mins[0] = ps[0];
        maxes[ps.size() - 1] = ps[ps.size() - 1];
        for (int i = 1; i < ps.size(); i++)
            mins[i] = min(mins[i - 1], ps[i]);
        for (int i = ps.size() - 2; i >= 0; i--)
            maxes[i] = max(mins[i + 1], ps[i]);

        for (int i = 0; i < ps.size(); i++) // we caclulate the min and max for each possible pos and update the result
            res = max(res, maxes[i] - mins[i]);

        return res;
    }
};