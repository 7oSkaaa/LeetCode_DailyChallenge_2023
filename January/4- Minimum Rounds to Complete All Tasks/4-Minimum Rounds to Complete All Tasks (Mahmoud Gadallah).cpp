/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;       //frequency of each element

        for (auto &x : tasks)       //storing frequency
            freq[x]++;
        
        int ans = 0;        

        /*
            iterate over freq map and check
            vaild cases is numbers greater than 1
            otherwise if number is divisible by 3 then number of rounds is freq/3, 
            if not we just add around (freq/3) + 1
        */
        for (auto &x : freq) {
            if (x.second < 2)       return -1;
            ans += (x.second/3) + (x.second%3 != 0);
        }

        return ans;
    }
};