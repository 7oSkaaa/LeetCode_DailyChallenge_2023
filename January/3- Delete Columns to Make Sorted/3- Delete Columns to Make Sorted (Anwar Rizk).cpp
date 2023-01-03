// Author: Anwar Rizk

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].length(), ans = 0;
        for(int i = 0; i < m; i++)  // for each column
        {
            for(int j = 1; j < n; j++)  // for each row
            {
                // if the current character is less than the previous one in the same column
                // then we delete this column and break
                if(strs[j][i] < strs[j - 1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};