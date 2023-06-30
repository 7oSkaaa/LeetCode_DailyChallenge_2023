// Author: Ahmed Gamal

// for this problem, we will serialize each row and each column and store the frequency of each serialized row and column in a map as a string

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // freq: the frequency of each serialized row
        unordered_map<string, int> freq;

        // for each row, serialize it and store the frequency of the serialized row in the map
        for(auto& row : grid) {
            string s_row;
            for(auto& x : row) {
                // we will use ',' as a separator between the elements of the row
                s_row += (s_row.empty() ? "" : ",") + to_string(x);
            }
            freq[s_row]++;
        }

        // for each column, serialize it and add the frequency of the serialized column to the answer
        // this will be the number of equal rows
        int ans = 0;
        for(int j = 0; j < grid[0].size(); j++) {
            string s_col;
            for(int i = 0; i < grid.size(); i++) {
                s_col += (s_col.empty() ? "" : ",") + to_string(grid[i][j]);
            }
            ans += freq[s_col];
        }

        return ans;
    }
};