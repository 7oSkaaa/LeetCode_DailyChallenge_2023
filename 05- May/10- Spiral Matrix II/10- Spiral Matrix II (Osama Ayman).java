// Author: Osama Ayman
// Time: O(n*n)
// Space: O(1) not counting the output matrix
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int cnt = 1;
        int size = n*n;
        int curLevel = 0;
        while(cnt <= size){
            // top row
            for(int j=curLevel; j < n-curLevel; j++){
                res[curLevel][j] = cnt++;
            }
            
            // right col
            for(int i=curLevel+1; i < n-curLevel; i++){
                res[i][n-curLevel-1] = cnt++;
            }
            
            // bottom row
            for(int j=n-curLevel-2; j >= curLevel; j--){
                res[n-curLevel-1][j] = cnt++;
            }
            
            // left col
            for(int i=n-curLevel-2; i > curLevel; i--){
                res[i][curLevel] = cnt++;
            }
            curLevel++;
        }

        return res;
    }
}