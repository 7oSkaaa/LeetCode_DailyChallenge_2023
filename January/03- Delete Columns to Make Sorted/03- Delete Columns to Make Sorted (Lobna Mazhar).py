# Author: Lobna Mazhar

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # Initialize a counter for the final result
        res = 0
        # Loop on the list column by column, it wil be the length of any string from the list as they all have the same length
        for i in range(len(strs[0])):
            # Check all the strings for the current column starting from the second (index-1) string to compare it by the previous string
            for j in range(1, len(strs)):
                # Check if the current char is smaller than the previous one, then column is not sorted; increment the counter and break the loop for the current column
                if strs[j][i] < strs[j-1][i]:
                    res += 1
                    break
        # return the counter
        return res
