#include<bits/stdc++.h>

// Author: Mahmoud Gadallah

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();        //n --> num of words, m --> size of each word
        int cnt = 0;            //cnt --> contains number of deleted columns

        for (int j = 0; j < m; ++j) {           //iterate over columns
            for (int i = 1; i < n; ++i) {       //iterate over rows
                if (strs[i][j] < strs[i-1][j]) {   //checking if curr char is less than char above it in columns then we should delete this column
                    ++cnt;
                    break;
                }
            }
        }

        return cnt;
    }
};