// Author: Mahmoud Aboelsoud

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // get our grid dimensions
        int rows = strs.size();
        int cols = strs[0].size();

        int num_of_not_sorted = 0;

        // loop on the grid columns
        for(int col = 0; col < cols; col++){
            // assume that the current column is sorted
            bool sorted = true;

            // loop on the rows of the current column
            for(int row = 1; row < rows; row++){
                // check if our assumption is false by comparing the current character with the previous one
                // for our assumption to be true the current character should be greater than or equal to the previous one
                if(strs[row][col] < strs[row - 1][col]){
                    // if the cuurent character is smaller than the previous one that means that our assumption 
                    // is false and the current column isn't sorted
                    sorted = false;
                    num_of_not_sorted++;
                    break;
                }
            }
        }
      
        return num_of_not_sorted;
    
    }
};
