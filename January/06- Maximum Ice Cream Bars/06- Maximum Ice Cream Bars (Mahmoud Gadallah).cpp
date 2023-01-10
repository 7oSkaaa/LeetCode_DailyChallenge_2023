/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int cnt = 0;        //cnt --> number of iceCreams

        //keep taking icreames until coins > 0
        for (auto &cost : costs) {
            coins -= cost;
            if (coins < 0)
                return cnt;
            ++cnt;
        }

        return cnt;
    }
};