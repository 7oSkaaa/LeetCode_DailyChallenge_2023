// author : Omar Sanad
class Solution {
public:
    vector < vector <int> > pref, dp;
    int rec(int RowIdx, int k) {

        // (Base Case)  if we reached the end of rows
        if (RowIdx == pref.size()) return 0;

        // dp step
        int &ret = dp[RowIdx][k];
        if (~ret)   return ret;
        
        // iterate throw the prefix array of the current row
        // and maximize the ret
        for (int i = 0; i <= k && i < pref[RowIdx].size(); i++)
            ret = max(ret, pref[RowIdx][i] + rec(RowIdx + 1, k - i));
        
        // return the ret after we have maximized and tried all possible cases
        return ret;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        // resize the global prefix grid, and the dp table
        int n = piles.size();
        pref.resize(n);
        dp.assign(n, vector <int> (k + 1, -1));


        for (int i = 0; i < n; i++) {

            // resize the prefix array of the current row
            pref[i].resize(piles[i].size() + 1);

            // calculate the prefix array of the current row
            for (int j = 0; j < piles[i].size(); j++)
                pref[i][j + 1] = pref[i][j] + piles[i][j];
    
        }

        return rec(0, k);
    }
};
