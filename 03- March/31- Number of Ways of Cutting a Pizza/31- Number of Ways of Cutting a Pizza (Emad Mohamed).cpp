//Author: Emad Mohamed
/*
  We will use DP to try all the possible solutions.

  Dp represents the piece from (x, y) to (n, m) with k remaining cuts.

  We can go through each row (except the last) and try to cut 
  from there and see if the one above it is valid.

  Then go through each column (except the last) and cut from there
  to see if the one to left of it is valid.

  We can't cut from the last row or column because there would
  be nothing below the cut to continue our dp.

  The base case is when we have done k - 1 cuts and we have to 
  check that the last piece is valid.

  We check the validity of each piece using 2d prefix sum
  to make sure that each one has atleast one apple.
*/
class Solution {
    int n, m, dp[51][51][11], mod = 1e9 + 7;
    vector<vector<int>>pref;

    bool is_valid_piece(int x1, int y1, int x2, int y2){
        return (pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1]) > 0;
    }

    int findCnt(int x, int y, int k){
        if(!k)
            return is_valid_piece(x, y, n, m);
        int& ret = dp[x][y][k];
        if(~ret) return ret;
        ret = 0;
        // try to cut from each row
        for(int row = x; row < n; row++)
            if(is_valid_piece(x, y, row, m))
                ret += findCnt(row + 1, y, k - 1), ret %= mod;
        // try to cut from each column
        for(int col = y; col < m; col++)
            if(is_valid_piece(x, y, n, col))
                ret += findCnt(x, col + 1, k - 1), ret %= mod;
        return ret;
    }
public:
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        n = pizza.size(), m = pizza[0].size();
        // Prefix sum is one indexed to make calculations easier
        pref.resize(n + 1, vector<int>(m + 1));
        pref[1][1] = (pizza[0][0] == 'A');
        for(int i = 2; i <= n; i++)
            pref[i][1] = pref[i - 1][1] + (pizza[i - 1][0] == 'A');
        for(int i = 2; i <= m; i++)
            pref[1][i] = pref[1][i - 1] + (pizza[0][i - 1] == 'A');
        for (int i = 2; i <= n; i++) 
            for (int j = 2; j <= m; j++)
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
        return findCnt(1, 1, k - 1);
    }
};
