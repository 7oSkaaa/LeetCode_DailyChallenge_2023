#include <bits/stdc++.h>
using namespace std;
// Author: Hamza Hassanain
class Solution
{
public:
    int pivot = 0;
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
                j++;
            int len = j - i;
            chars[pivot++] = chars[i];
            if (len > 1)
            {
                int oldPivot = pivot;
                while (len)
                {
                    int digit = len % 10;
                    chars[pivot++] = digit + '0';
                    len /= 10;
                }
                reverse(chars.begin() + oldPivot, chars.begin() + pivot);
            }
            i = j - 1;
        }

        return pivot;
    }
};