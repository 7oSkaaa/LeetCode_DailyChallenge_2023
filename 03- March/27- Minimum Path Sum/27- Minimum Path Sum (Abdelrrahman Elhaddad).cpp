//Author: Abdelrrahman Elhaddad

class Solution {
private:
const int oo = 0x3f3f3f3f; //The maximum value
vector<vector<int>> dp; //To store the minium sum from the end point to each node, So not calculate it each time you visit it
int n, m;

public:
bool isValid(int i, int j) { // To check for whether the node I want to visit in is in vector boundries or not
    return i < n && j < m && i >= 0 && j >= 0;
}

int rec(int i, int j, vector<vector<int>> &grid) {
    if (i == n - 1 && j == m - 1) //If the end point reached, just return the value of it
        return grid[i][j];

    int &ans = dp[i][j]; //Make a refrence variable to the node's place in the dp vector
    if (~ans) // If the ans does not equal -1 return it, that means I have visited before
        return ans;
    ans = oo; // If not visited set to to the maximum (because we want to minimumize)

    if (isValid(i + 1, j)) 
        ans = min(ans, grid[i][j] + rec(i + 1, j, grid)); // Move to the right
    if (isValid(i, j + 1)) 
        ans = min(ans, grid[i][j] + rec(i, j + 1, grid)); // Move to the left

    return ans;
}

int minPathSum(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    dp.assign(n, vector<int>(m, -1)); // Filling the dp vector with -1
    return rec(0, 0, grid);
}

};
