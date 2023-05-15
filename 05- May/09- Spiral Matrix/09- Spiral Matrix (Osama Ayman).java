// Author: Osama Ayman
// Time: O(n*m)
// Space: O(1) not counting the output array list
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int cnt=0, rows = matrix.length, cols = matrix[0].length;
        int size = rows*cols;
        int curLevel = 0;
        List<Integer> res = new ArrayList<>();
        while(cnt < size){
            // top row
            for(int j=curLevel; j<cols-curLevel; j++){
                res.add(matrix[curLevel][j]);
                cnt++;
            }
            if(cnt==size) break;
            // left col
            for(int i=curLevel+1; i<rows-curLevel; i++){
                res.add(matrix[i][cols-curLevel-1]);
                cnt++;
            }
            if(cnt==size) break;
            // bottom row
            for(int j=cols-curLevel-2; j>=curLevel; j--){
                res.add(matrix[rows-curLevel-1][j]);
                cnt++;
            }
            if(cnt==size) break;
            // right col
            for(int i=rows-curLevel-2; i > curLevel; i--){
                res.add(matrix[i][curLevel]);
                cnt++;
            }
            curLevel++;
        }
        return res;
    }
} 