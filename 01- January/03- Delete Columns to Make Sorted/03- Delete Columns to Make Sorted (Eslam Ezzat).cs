// Author: Eslam Ezzat 

// Time Complexity: O(Number of columns * Number of rows)

// Space Complexity: O(Number of columns)

public class Solution
{
    public int MinDeletionSize(string[] strs)
    {
        // First, get the size of num of rows, num of columns.
        // Making counter variable equal to (zero) to count the number of non-sorted columns. 
        int numOfRows = strs.Length,numOfColumns = strs[0].Length,
            counter = 0;

        // Iterate through array of strs according to rows and columns.
        for (int i = 0; i < numOfColumns; i++)
        {
            // Making an empty variable called storeEachColumn to store each column.
            string storeEachColumn = "";

            for (int j = 0; j < numOfRows; j++)
            {
                storeEachColumn += strs[j][i];
            }

            // Get the size of column.
            int sizeOfColumn = storeEachColumn.Length;

            // Making boolean variable to check if the column is sorted or not
            Boolean checkSortedOrNot = false;
            for (int k = 1; k < sizeOfColumn; k++)
            {
                if (storeEachColumn[k] < storeEachColumn[k - 1])
                {
                    checkSortedOrNot = true;
                    break;
                }
            }
            if (checkSortedOrNot)
                counter++; // It increases by 1 if the column is non-sorted.
        }
        return counter;
    }
}