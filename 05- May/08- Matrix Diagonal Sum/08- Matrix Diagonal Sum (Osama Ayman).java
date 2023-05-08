// Author: Osama Ayman
// Time: O(mat.length)
// Space: O(1)
class Solution {
    public int diagonalSum(int[][] mat) {
        // if the size of mat is even they the primary and secondary diagonals will 
        // not intersect.

        // They will only intersect if the size is odd.
        int n = mat.length;
        int res = 0;
        for(int i=0; i<n; i++){
            // primary diagonal
            res += mat[i][i];
            // secondary diagonal
            res += mat[i][n-i-1];
        }
        // if odd, then the middle number was counted twice, so remove it
        if(n%2==1) res -= mat[n/2][n/2];
        return res;
    }
}