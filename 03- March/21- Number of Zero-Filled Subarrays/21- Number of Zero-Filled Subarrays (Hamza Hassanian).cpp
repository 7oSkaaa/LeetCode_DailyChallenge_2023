// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    Approach:
        we will be keeping a counter to our length of the current subarray filled with zeros
        and when we encouter an a non-zero element or exit our array we can add the
        summation of the zeros length we found [(zeros) + (zeros-1) + (zeros-2) +........(zeros-zeros)] because the number of
        subarrays in a possible range is the summation of the length of the [range + (range-1)............(range-range)]
*/
class Solution
{
public:
    long long summation(long long num)
    {
        return num * (num + 1) / 2;
    }
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0, zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (!nums[i])
                zeros++;
            else
                res += summation(zeros), zeros = 0;
        }
        res += summation(zeros);
        return res;
    }
};