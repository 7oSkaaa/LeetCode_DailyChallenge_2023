/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

// # Intuition
// how can we know judges? 
// - they don't trust any one 
// - also all people trust them

// # Approach
// so we want to mark people who trust others so will use an Auxaliry array and mark people who trust other with -1 and add there trust to the people who trust them after doing that we iterate over array and check if any one number of people who trust him is equal to n - 1 people so we return him other wise we return -1

// # Complexity
// - Time complexity:
// O(N)

// - Space complexity:
// O(N)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> mark(n+1, 0);

        for (auto &x : trust) {
            mark[x[0]] = -1;
            if (mark[x[1]] != -1)   mark[x[1]]++;
        }

        for (int i = 1; i <= n; ++i)
            if (mark[i] == n - 1)       return i;

        return -1;
    }
};
