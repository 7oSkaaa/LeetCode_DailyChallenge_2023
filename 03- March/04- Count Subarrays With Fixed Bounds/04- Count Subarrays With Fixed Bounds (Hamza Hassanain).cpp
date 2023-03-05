// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    Approach:
        1-> Splite the arrays into parts inorder to be easier to work with where rach part
            contains values that are in the interval [minK,maxK]
        2-> Keep track of our last minK and last maxK index and when when adding a new element
            calculate the number of arrays
*/
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int mn, int mx)
    {
        int n = nums.size();
        vector<pair<int, int>> subarrays; // segments of the array where all values are in the interval [minK,maxK]
        int l = 0;
        int r = 0;
        while (r < n)
        {
            if (nums[r] > mx || nums[r] < mn)
            {
                if (r)
                    subarrays.push_back({l, r - 1});
                r++;
                l = r;
            }
            else
                r++;
        }
        if (r >= n && l < r) // if last segment then added
            subarrays.push_back({l, r - 1});

        long long res = 0;
        for (auto sub : subarrays)
        {
            auto [cur, end] = sub;
            int beg = cur;
            int lastMin = -1;
            int lastMax = -1;

            while (cur <= end)
            {

                if (nums[cur] == mn)
                    lastMin = cur;
                if (nums[cur] == mx)
                    lastMax = cur;

                if (lastMin != -1 && lastMax != -1)
                    res += min(lastMin, lastMax) + 1 - beg; // calculate the number of arrays

                cur++;
            }
        }

        return res;
    }
};