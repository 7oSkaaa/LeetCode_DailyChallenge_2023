/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/** Approach
 * how to know if number of points represent a line?
 *  - simply with getting slopes between each 2 points if they are have the same line then it can represent a line
 * so we get slope between every 2 points and most frequent slope it's the longest line which have most points
 * 
 * Time complexity: O(N^2)
 * Space Complexity: O(map.size())
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx = 0;

        for (auto &p1 : points) {
            unordered_map<double, int> freq;        //freq --> frequency of slopes
            for (auto &p2: points) {
                double slope = INT_MIN;
                
                if (p1 == p2)       continue;       //if the same skip it

                if (p1[0] != p2[0])         // diff(x1, x2) == 0 get error devision by zero (vertical line)
                    slope = (double) (p2[1] - p1[1]) / (p2[0] - p1[0]);

                mx = max(mx, ++freq[slope]);            //get max slope frequency
            }
        }

        return mx + 1;
    }
};