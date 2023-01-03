//Author: Mohamed Ibrahim

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
           if (strs.empty()) return 0;
    int n = strs.size(), m = strs[0].size();
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (strs[j][i] < strs[j - 1][i]) {
                res++;
                break;
            }
        }
    }
    return res;
    }
};