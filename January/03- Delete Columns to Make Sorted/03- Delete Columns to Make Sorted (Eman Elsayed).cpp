// Author : Eman Elsayed

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int cnt = 0; // Number of unsorted Coloumns
        // dimension of the grid
        int col = strs[0].size();
        int row = strs.size();
        // iterate on each Coloums in the grid and Check if this Coloumn Sorted or Not
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row - 1; j++)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    cnt++;
                    break;
                }
            }
        }
        // Return Answer
        return cnt;
    }
};