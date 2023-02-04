// Author: Osama Ayman
class Solution {
    public int minDeletionSize(String[] strs) {
        /*
            1. start with the first column: first letter in each word.
            2. loop over all the words and check if the current character of a later word is smaller than that of the current word, then this column is unsorted.
            3. If this column is unsorted, increment the counter by 1 and break, beacuse
            (we have set this column to be deleted. So, there is no need to check the rest of the words for this column.)
        */ 
        int curCol = 0, cols = strs[0].length(), res = 0;
        while(curCol < cols){
            for(int i=1; i<strs.length; i++){
                if(strs[i-1].charAt(curCol) > strs[i].charAt(curCol)  ) {res++; break;}
            }
            curCol++;
        }
        return res;
    }
}