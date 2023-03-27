//Author: Abdelrrahman Elhaddad

let dp: number[][] = []; //To store the minium sum from the end point to each node, So not calculate it each time you visit it
let n: number, m: number;

function fillDP(): void { // A function to fill dp array with -1 in all of its indexes
    for (let i = 0; i < n; i++) {
        dp[i] = [];
        dp[i].length = m;
        for (let j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }
}

function isValid(i: number, j: number): boolean { // To check for whether the node I want to visit in is in vector boundries or not
    return i >= 0 && j >= 0 && i < n && j < m;
}

function minPathSum(grid: number[][]): number {
    n = grid.length, m = grid[0].length;
    dp.length = n;

    fillDP();
    return rec(0, 0);

    function rec(i: number, j: number): number {
        if (i == n - 1 && j == m - 1) //If the end point reached, just return the value of it
            return grid[i][j];

        if (~dp[i][j]) // If the ans does not equal -1 return it, that means I have visited before
            return dp[i][j];
        let ans = Infinity; // If not visited set to to the maximum (because we want to minimumize)

        if (isValid(i + 1, j))
            ans = Math.min(ans, grid[i][j] + rec(i + 1, j)); // Move to the right
        if (isValid(i, j + 1))
            ans = Math.min(ans, grid[i][j] + rec(i, j + 1)); // Move to the left

        dp[i][j] = ans;
        return ans;
    }
};
