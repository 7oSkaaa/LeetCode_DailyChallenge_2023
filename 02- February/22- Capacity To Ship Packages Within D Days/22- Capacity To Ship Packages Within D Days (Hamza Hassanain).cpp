// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int max(vector<int> &nums)
    {
        int n = size(nums);
        int mx = -1e9;
        for (int i = 0; i < n; i++)
            mx = ::max(mx, nums[i]);
        return mx;
    }
    int get_days(vector<int> &weights, int cap)
    {
        int days = 1;
        int cur = cap;
        for (int i = 0; i < weights.size(); i++)
        {
            if (cur - weights[i] < 0)
                days++, cur = cap;

            cur -= weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int mn = max(weights);                   // set the minimum capacity to the max weight of the array
        int mx = (size(weights) * max(weights)); // set the maximum capacity to the max weight of the array
        // boundries of the binary search
        int res = -1;
        while (mn <= mx)
        {
            int md = (mx + mn) / 2;
            int cur_days = get_days(weights, md); // count the days required to ship the weights
            if (cur_days <= days)                 // if the days is less than or equal to days required we set it as a possible answer and search for a minimum answer
            {
                res = md;
                mx = md - 1;
            }
            else if (cur_days > days)
                mn = md + 1;
            else
                mx = md - 1;
        }
        return res;
    }
};
