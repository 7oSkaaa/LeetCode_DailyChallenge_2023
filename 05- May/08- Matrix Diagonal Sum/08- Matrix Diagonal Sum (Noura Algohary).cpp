// Author: Noura Algohary
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;
        int n = mat.size();

        for(int i = 0; i<n; i++)
        {
            for(int j = 0;j <n;j++)
                {
                    if(i + j == n - 1 || i == j)
                        result += mat[i][j];
                }
        }

        return result;
    }
};