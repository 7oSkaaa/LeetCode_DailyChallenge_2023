//Author: Mohamed Ibrahim

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // if the input array is empty, return 0
        if (strs.empty()) return 0;
        // store the number of rows and columns in the array
         int n = strs.size(), m = strs[0].size();
        int res = 0;
        // iterate over each column
        for (int i = 0; i < m; i++) {
        // iterate over each row except the first row
         for (int j = 1; j < n; j++) {
        /* if the current character in the column is less than the character in
        the same column of the previous row, increment the result variable and break the inner loop*/
            if (strs[j][i] < strs[j - 1][i]) {
                res++;
                break;
            }
        }
     }
    return res;
    }
};