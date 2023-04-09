//Author: Abdelrrahman Elhaddad


class Solution {
private:
int n, m;
int dp[55][55][13]; // Memoization 
long long MOD = 1000000007;

public:
// Check whether the remaining peice contains apples
bool checkRem(int i, int j, vector<string> &pizza) { 
    for (int ii = i; ii < n; ii++)
        for (int jj = j; jj < m; jj++)
            if (pizza[ii][jj] == 'A')
                return true;
    return false;
}

// Check whther the cut peice contains apples
bool checkCut(int i, int j, int ii, int jj, vector<string> &pizza) {
    for (int idx1 = i; idx1 < ii; idx1++)
        for (int idx2 = j; idx2 < jj; idx2++)
            if (pizza[idx1][idx2] == 'A')
                return true;
    return false;
}

long long rec(int i, int j, int cuts, vector<string> &pizza) {
    if (!checkRem(i, j, pizza)) // If the current peice doesn't contain apples return 0
        return 0;
    if (cuts == 1) // If the the current cut's size is 1 that means that we find a valid way to cut the pizza, So return 1
        return 1;

    // Our memoization depends on three values
    // 1- the latest vertically cut (i)
    // 2- the latest horizontally cut (j)
    // 3- my remaining cuts (cuts)
    int &ans = dp[i][j][cuts]; 
    if (~ans)
        return ans;
    ans = 0;

    // Cutting horizantally in all possiblities []if the cut peice contains apples]
    for (int ii = i + 1; ii < n; ii++) {
        if (checkCut(i, j, ii, m, pizza))
            ans += rec(ii, j, cuts - 1, pizza) % MOD;
        ans %= MOD;
    }

    // Cutting vertically in all possiblities [if the cut peice contains apples]
    for (int jj = j + 1; jj < m; jj++) {
        if (checkCut(i, j, n, jj, pizza))
            ans += rec(i, jj, cuts - 1, pizza) % MOD;
        ans %= MOD;
    }

    return ans % MOD;
}

int ways(vector<string> &pizza, int k) {
    n = pizza.size();
    m = pizza[0].size();
    memset(dp, -1, sizeof dp); // Filling our memoization array
    return rec(0, 0, k, pizza) % MOD;
}
};
